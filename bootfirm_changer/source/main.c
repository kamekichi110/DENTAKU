#include <3ds.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define SOURCE_PATH "/firms/"
#define DEST_PATH "/boot.firm"

typedef struct {
    char name[256];
} FirmFile;

FirmFile firmFiles[256];
int firmCount = 0;
int selectedIndex = 0;

void listFirmFiles() {
    DIR *dir;
    struct dirent *ent;
    firmCount = 0;

    if ((dir = opendir(SOURCE_PATH)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".firm") != NULL) {
                strncpy(firmFiles[firmCount].name, ent->d_name, sizeof(firmFiles[firmCount].name) - 1);
                firmFiles[firmCount].name[sizeof(firmFiles[firmCount].name) - 1] = '\0';
                firmCount++;
            }
        }
        closedir(dir);
    }
}

void copyFirmFile(const char *source, const char *dest) {
    FILE *srcFile = fopen(source, "rb");
    FILE *dstFile = fopen(dest, "wb");

    if (srcFile == NULL || dstFile == NULL) {
        printf("Failed to open source or destination file.\n");
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, dstFile);
    }

    fclose(srcFile);
    fclose(dstFile);
}

void drawUI() {
    consoleClear();
    printf("\x1b[1;37mboot.firm changer by kamekichi110\x1b[0m\n");
    for (int i = 0; i < firmCount; i++) {
        if (i == selectedIndex) {
            printf("\x1b[31m> %s\x1b[0m\n", firmFiles[i].name); // Red color for selected
        } else {
            printf("\x1b[33m  %s\x1b[0m\n", firmFiles[i].name); // Yellow color for others
        }
    }
}

void promptConfirmation(const char *fileName) {
    consoleClear();
    printf("\x1b[1;37mDo you change boot.firm to your selected %s file?\x1b[0m\n", fileName);
    printf("\x1b[1;37mPress A to confirm, B to cancel.\x1b[0m\n");
}

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    listFirmFiles();
    drawUI();

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_DOWN) {
            selectedIndex = (selectedIndex + 1) % firmCount;
            drawUI();
        } else if (kDown & KEY_UP) {
            selectedIndex = (selectedIndex - 1 + firmCount) % firmCount;
            drawUI();
        } else if (kDown & KEY_A) {
            promptConfirmation(firmFiles[selectedIndex].name);
            while (1) {
                hidScanInput();
                u32 kDown2 = hidKeysDown();
                if (kDown2 & KEY_A) {
                    char sourceFilePath[512];
                    snprintf(sourceFilePath, sizeof(sourceFilePath), "%s%s", SOURCE_PATH, firmFiles[selectedIndex].name);
                    copyFirmFile(sourceFilePath, DEST_PATH);
                    consoleClear();
                    printf("\x1b[1;37mboot.firm changed successfully. Rebooting...\x1b[0m\n");
                    // Add reboot code here if necessary
                    svcSleepThread(5000000000); // Wait for 5 seconds
                    break;
                } else if (kDown2 & KEY_B) {
                    drawUI();
                    break;
                }
            }
        } else if (kDown & KEY_B) {
            break; // Exit
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}

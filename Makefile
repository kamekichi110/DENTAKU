include $(DEVKITARM)/3ds_rules

TARGET := nandemo_ya
BUILD := build
SOURCE := src
INCLUDE := include
DATA := data

CFILES := $(foreach dir,$(SOURCE),$(notdir $(wildcard $(dir)/*.c)))
OFILES := $(patsubst %.c,%.o,$(CFILES))

INCLUDE := -I$(INCLUDE) -I$(DEVKITPRO)/libctru/include

CFLAGS := -g -Wall $(INCLUDE)
LDFLAGS := -specs=3dsx.specs -g

$(BUILD)/$(TARGET).3dsx: $(OFILES)
	@echo linking ... $(TARGET).3dsx
	@$(LD) $(LDFLAGS) -o $@ $(OFILES)

%.o: %.c
	@echo compiling ... $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(BUILD)/*.o $(BUILD)/*.3dsx

# Basic Makefile for 3DS Homebrew
TARGET := boot_firm_changer
BUILD := build
SOURCE := source
INCLUDES := include
LIBS := -lctru -lm

# Uncomment to enable debug mode
# DEBUG := 1

#------------------------------------------------------------------------------#
# Options for devkitARM and libctru
#------------------------------------------------------------------------------#
ifneq ($(strip $(DEVKITARM)),)
  export DEVKITARM ?= $(shell unset PKG_CONFIG_LIBDIR; . $(DEVKITARM)/devkitarm.sh && echo $$DEVKITARM)
  export PATH := $(DEVKITARM)/bin:$(PATH)
endif

CFLAGS := -g -Wall -O2
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
LDFLAGS := -specs=3dsx.specs

#------------------------------------------------------------------------------#
# Automatic build flags depending on DEBUG option
#------------------------------------------------------------------------------#
ifneq ($(strip $(DEBUG)),)
  CFLAGS += -DDEBUG
  CXXFLAGS += -DDEBUG
endif

#------------------------------------------------------------------------------#
# Directories and Files
#------------------------------------------------------------------------------#
BUILD := build
SOURCES := $(wildcard $(SOURCE)/*.c)
OBJECTS := $(SOURCES:$(SOURCE)/%.c=$(BUILD)/%.o)
DEPS := $(OBJECTS:.o=.d)

#------------------------------------------------------------------------------#
# Rules
#------------------------------------------------------------------------------#
.PHONY: all
all: $(TARGET).3dsx

$(TARGET).3dsx: $(OBJECTS)
	@echo linking ... $@
	@$(CXX) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $@

$(BUILD)/%.o: $(SOURCE)/%.c
	@echo compiling ... $<
	@mkdir -p $(BUILD)
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean
clean:
	@echo cleaning ...
	@rm -f $(BUILD)/*.o $(BUILD)/*.d $(TARGET).3dsx
	@rm -rf $(BUILD)

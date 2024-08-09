# Project Name
TARGET = TouchMIDI

# Sources
CPP_SOURCES = $(wildcard *.cpp) $(wildcard touch/*.cpp)

# Library Locations
LIBDAISY_DIR = lib/libDaisy/
DAISYSP_DIR = lib/DaisySP/

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

CPP_STANDARD = -std=gnu++17

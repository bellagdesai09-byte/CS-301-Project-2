# CS302 Project 2 Makefile (template)
# You are expected to add your own .cpp files as your project grows.
# Start with driver.cpp. As you create new source files, add them to SRCS.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Executable name (feel free to rename)
TARGET = project2

# ------------------------------------------------------------
# Source files
# Add your .cpp files here as you create them.
# NOTE: Lines must end with a backslash (\) except the last line.
# ------------------------------------------------------------
SRCS = $(SRC_DIR)/driver.cpp \

# Object files (in build directory)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable path
EXECUTABLE = $(BUILD_DIR)/$(TARGET)

# Phony targets (not files)
.PHONY: all clean run

all: $(EXECUTABLE)

# Build the executable by linking object files
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS)

# Compile each .cpp into a .o in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE)

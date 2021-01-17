# ----------------------------------------------------------------------------
# Matthew James Lewis - VE6JI
# Green::Box(Code)
# ve6mjl@gmail.com
# ----------------------------------------------------------------------------
# Makefile Credit to © Arash Partow. All Rights Reserved. http://www.partow.net/programming/makefile/index.html

CXX      := g++
CXXFLAGS := -v -Wall -std=c++20 -march=znver1 -mtune=znver1 -g -Wextra -Os
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := sine
INCLUDE  := -Ihdr/
SRC      := $(wildcard src/*.cpp)	

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

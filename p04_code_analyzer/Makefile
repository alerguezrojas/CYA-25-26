CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -fsanitize=address -Wall -Wextra
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

TARGET = p04_code_analyzer

# Lista de archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.cc)
BUILDS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(BUILDS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
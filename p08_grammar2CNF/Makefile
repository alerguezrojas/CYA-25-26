# ===============================
#  Makefile - P08 Grammar to CNF Converter
#  Universidad de La Laguna - CyA
#  Autor: Alejandro Rodríguez Rojas
# ===============================

# Compilador y opciones
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2 -Iinclude

# Directorios
SRC_DIR := src
INC_DIR := include
BIN_DIR := bin
OBJ_DIR := obj

# Archivos fuente y objeto
SRCS := $(wildcard $(SRC_DIR)/*.cc)
OBJS := $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRCS))

# Nombre del ejecutable
TARGET := $(BIN_DIR)/p08_grammar2CNF

# ===============================
#  Reglas principales
# ===============================

all: $(TARGET)

# Enlazado final
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de cada .cc → .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ===============================
#  Utilidades
# ===============================

# Limpieza de objetos y binarios
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Limpieza total + recompilación
rebuild: clean all

# Ejecutar con un ejemplo (si tienes automata.fa e input.txt)
run: all
	@echo "Ejecutando ejemplo..."
	$(TARGET) automata.fa input.txt

# ===============================
#  Fin del Makefile
# ===============================

# Diretórios
SRC_DIR = src
TIME_DIR = time
MAIN_DIR = main
BUILD_DIR = build
BIN_DIR = bin

# Compiler e flags
CC = gcc
CFLAGS = -Wall -I$(SRC_DIR) -I$(TIME_DIR)

# Criação de diretórios (garante que existam)
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# Arquivos fonte
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TIME_FILES = $(wildcard $(TIME_DIR)/*.c)
MAIN_FILES = $(wildcard $(MAIN_DIR)/*.c)

# Objetos
SRC_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TIME_OBJS = $(patsubst $(TIME_DIR)/%.c,$(BUILD_DIR)/%.o,$(TIME_FILES))
MAIN_OBJS = $(patsubst $(MAIN_DIR)/%.c,$(BUILD_DIR)/%.o,$(MAIN_FILES))

OBJS = $(SRC_OBJS) $(TIME_OBJS) $(MAIN_OBJS)

# Binário final
TARGET = $(BIN_DIR)/main.e

# Regra principal
all: $(TARGET)

# Gera o binário
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compilar objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TIME_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(MAIN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

cleanimages:
	rm -f output/*.pgm output/*.p

.PHONY: all clean cleanimages

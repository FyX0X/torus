OBJ_DIR=build
SRC_DIR=src
HEADERS_DIR=headers

CC=clang

CPPFLAGS=-Iinclude -Iheaders
CFLAGS= #-g
LDLFLAGS=
LDLIBS=-lm


TARGET=torus


# --- SOURCE & OBJECTS ---

SOURCES = $(shell find $(SRC_DIR) -name '*.c')
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# for testing
# OBJECTS_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJECTS))
# TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
# TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.c, $(TEST_OBJ_DIR)/%.o, $(TEST_SOURCES))

# List path to headers files
HEADERS = $(shell find $(HEADERS_DIR) -name '*.h')

# --- rules ---

all: $(TARGET)


$(TARGET): $(OBJECTS)
	@echo "Linking $@..."
	@$(CC)  $^ $(LDFLAGS) $(LDLIBS) -o $@


# Rule to create subdirectories in build/ automatically
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "  CC      $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


clean:
	@rm -f $(TARGET) $(OBJECTS)
	@rm -rf $(OBJ_DIR)

format:
	@find . \( -name "*.c" -o -name "*.h" \) | xargs clang-format -i

.PHONY: all clean format

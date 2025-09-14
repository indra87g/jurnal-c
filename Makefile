# Compiler & Tools
CC      := clang
RM      := rm -rf
CFLAGS  := -Wall -O3
ARGS    := -c -o

# Directories
SRCDIR   := src
BUILDDIR := build
BINDIR   := bin
VENDOR   := vendor
TARGET   := $(BINDIR)/main

# Sources & Objects for Main Build
SRC := $(shell find $(SRCDIR) -type f -name "*.c")
OBJ  := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))

# Includes
INC := -I include -I $(SRCDIR)

# Rules
$(TARGET): $(OBJ)
	@echo "Linking main ..."
	@mkdir -p $(BINDIR)
	$(CC) $(OBJ) -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@echo "Building $<..."
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) $(ARGS) $@ $<

clean:
	$(RM) $(BUILDDIR) $(BINDIR)
	$(RM) data.txt data.json player_data.json
format:
	clang-format -i $(wildcard */*.c) $(wildcard */*.h)

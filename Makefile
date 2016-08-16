TARGET = c-algorithms

CC = gcc -g
CFLAGS = -Wall -std=c99

LINKER = gcc -o
LFLAGS = -Wall -I. -lm

# Directories
INCLUDEDIR = ./include
SRCDIR = ./src
BINDIR = ./bin
OBJDIR = ./obj

SOURCES := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCLUDEDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)

.PHONEY: remove
remove:
	@$(rm) $(BINDIR)/*.exe

# Use @ so the commands won't echo on the console.

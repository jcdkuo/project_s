# ------------------------------------------------
# Generic Makefile
#
# Author: jcdkuo@gmail.com
# Date  : 2020-05-20
#
# Changelog :
#   2020-05-20 - first version
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = ndsl3

# change these to proper directories where each file should be
SRCDIR   = src
INCDIR   = inc
OBJDIR   = obj
BINDIR   = bin

# Detect system OS
detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')

# Clean the default value of CC
#CC       =

# Detect proper C compiler by system OS
ifndef CC
    ifeq ($(detected_OS),Darwin)
        CC = clang -arch x86_64
    else ifeq ($(detected_OS),Linux)
        CC = gcc
    else
        CC = gcc
    endif
endif

# compiling flags here
INC      = -I $(INCDIR)
LIB      = 
#DEF      = -DDEBUG
CFLAGS   = -std=c99 -g -Wall $(DEF) $(INC) $(LIB)

LINKER   = gcc
# linking flags here
LFLAGS   = -Wall -I. -lm

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" "

.PHONY: clean
clean:
	@echo "Cleaning...";
	@$(rm) $(OBJECTS)
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

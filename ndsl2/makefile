#
#CC := g++ # This is the main compiler
#CC := clang -arch x86_64 -std=c99 # and comment out the linker last line for sanity

ifndef CC
    ifeq ($(detected_OS),Darwin)
        CC = clang -arch x86_64
    else ifeq ($(detected_OS),Linux)
        CC = gcc
    else
        CC = gcc
    endif
endif

SRCDIR := src
BUILDDIR := build
TARGET := bin/ndsl2
  
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
#DEF := -DINITIAL_0
#DEF := -DINITIAL_1
DEF := -DINITIAL_2 -DSOPHIE_VER
#DEF := -DINITIAL_2 -DJERRY_VER
LIB := -L /usr/lib 
INC := -I inc

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(DEF) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(DEF) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET); $(RM) -r $(BUILDDIR) $(OBJECTS)

# Tests
#tester:
#$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean


#
## TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#
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
TARGET := bin/ndsl
  
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
LIB := -L /usr/lib 
INC := -I inc

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

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


CC := g++
CFLAGS := -Wall -std=c++11

SRCDIR := src
LIBDIR := lib
BUILDDIR := build
TARGETDIR := bin

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%.$(SRCEXT),%,$(SOURCES))
BIN := $(patsubst $(SRCDIR)/%.$(SRCEXT),$(TARGETDIR)/%,$(SOURCES))

INC := -I include

test:
	@echo "$(OBJECTS)"

all: $(OBJECTS)

$(OBJECTS): %: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -o bin/$@ $<

clean: 
	@echo "cleaning ..."
	rm -f $(BIN)

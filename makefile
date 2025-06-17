CC = gcc
WARNINGS = -Werror -Wextra -Wall -Wpedantic -Wshadow -Wconversion -Wsign-conversion
CFLAGS = $(WARNINGS) -std=c99 -I$(IDIR)
RELEASE = -O2
DEBUG = -g -ggdb

IDIR = ./include
SRCDIR = ./src
BUILDDIR = ./build

EXEC = reslogd

SRC = $(wildcard $(SRCDIR)/*.c)

all: clean $(BUILDDIR)/$(EXEC)

$(BUILDDIR)/$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(RELEASE) $(SRC) -o $@

debug: $(SRC)
	$(CC) $(CFLAGS) $(DEBUG) $(SRC) -o $@

clean:
	rm -rf ./build/*
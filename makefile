CC = gcc
WARNINGS = -Werror -Wextra -Wall -Wpedantic -Wshadow -Wconversion -Wsign-conversion
CFLAGS = $(WARNINGS) -std=c99 -I$(IDIR)
RELEASE = -O2
DEBUG = -g -ggdb

IDIR = ./include
SRCDIR = ./src
BUILDDIR = ./build

SRC = $(wildcard $(SRCDIR)/*.c)

all: clean reslogd

reslogd: $(SRC)
	$(CC) $(CFLAGS) $(RELEASE) $(SRC) -o $@

debug: $(SRC)
	$(CC) $(CFLAGS) $(DEBUG) $(SRC) -o $@

clean:
	rm -rf ./reslogd
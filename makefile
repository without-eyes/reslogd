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

.PHONY: all clean config script exec debug

all: clean config script $(BUILDDIR)/$(EXEC) exec

$(BUILDDIR)/$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(RELEASE) $(SRC) -o $@

debug: $(SRC)
	$(CC) $(CFLAGS) $(DEBUG) $(SRC) -o $@

config:
	cp ./config/reslogd /etc/logrotate.d/

script:
	sudo chmod +x ./script/reslogd
	cp ./script/reslogd /etc/init.d/

exec:
	cp ./build/reslogd /usr/bin/

clean:
	rm -rf ./build/*
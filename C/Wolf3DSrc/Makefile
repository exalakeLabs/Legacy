CC ?= cc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic
CPPFLAGS += -Iinclude
PORTABLE_SOURCES = src/portable/assets.c src/portable/framebuffer.c \
	src/portable/paths.c src/portable/persistence.c

.PHONY: all test clean
all: portable-tests

portable-tests: tests/portable_tests.c $(PORTABLE_SOURCES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

test: portable-tests
	./portable-tests

clean:
	rm -f portable-tests

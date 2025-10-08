CC = gcc
CFLAGS = -Iinclude -Wall -O2
LIBS = -lm

SRC_MODULES = $(wildcard src/*.c)

# Default: build all problems (optional)
PROBLEMS = $(wildcard 00*/)
TARGETS = $(PROBLEMS:%=%problem_%)

all: $(TARGETS)

# Rule to compile a single problem folder
%problem_%: %/main.c
	$(CC) $(CFLAGS) $(SRC_MODULES) $< -o $@ $(LIBS)

# Clean all binaries
clean:
	rm -f */problem_*

# Compile a specific problem folder
# Usage: make PROBLEM=0015
problem:
	$(CC) $(CFLAGS) $(SRC_MODULES) $(PROBLEM)/main.c -o $(PROBLEM)/main $(LIBS)

.PHONY: all clean problem

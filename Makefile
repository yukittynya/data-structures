CFLAGS = -Werror -O3 -ffast-math -flto
CC = clang 

STRUCTURES = linked_list hashtable binary_tree stack queue

build/bin/%: build/%/main.o build/%/lib.o | build/bin
	$(CC) $(CFLAGS) $^ -o $@

build/%/main.o: src/%/main.c | build/%
	$(CC) $(CFLAGS) -c $< -o $@

build/%/lib.o: src/%/lib.c | build/%
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

build/bin: | build
	mkdir -p build/bin

build/%: | build
	mkdir -p $@

.PHONY: $(STRUCTURES) clean run

$(STRUCTURES): %: build/bin/%

run: 
	@echo "Usage: make run STRUCT=<structure>"
	@echo "Available structures: $(STRUCTURES)"
	@echo "Example: make run STRUCT=linked_list"

ifdef STRUCT
run: clean build/bin/$(STRUCT)
	./build/bin/$(STRUCT)
endif

clean:
	rm -rvf build

help:
	@echo "Available targets:"
	@echo "  <structure>     - Build specific structure ($(STRUCTURES))"
	@echo "  run STRUCT=<s>  - Build and run specific structure"
	@echo "  clean          - Remove build directory"
	@echo "  help           - Show this help message"

.PHONY: help

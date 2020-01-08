#include <unistd.h>

int main()
{
	char* argv[] = { "/bin/bash", "-i", NULL };
	setuid(0), setgid(0);
	execve(argv[0], argv, NULL);
}

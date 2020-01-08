#include <unistd.h>

int main()
{
	char* shell = "/bin/bash";
	char* args[] = { shell, "-i", NULL };
	setuid(0), setgid(0);
	execve(shell, args, NULL);
}

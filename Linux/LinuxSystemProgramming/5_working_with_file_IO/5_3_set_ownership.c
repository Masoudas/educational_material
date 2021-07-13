/**
 * Similarly, we can set the ownership of a file or a folder with chown command.
 * 
 * We can consider the following program a simple version of the chown command. Notice how we tokenize a string
 * into username and password over the : token. Notice that the user gives the new owner and group as follows:
 * chown user:group filename
 * where both user and group are strings. We need to check whether they exists as proper users and groups, and
 * get their corresponding ids. To that end:
 * 
 * 	-	For user, a call to '$ apropos -s 3 "user.*name"' would reveal to us getpwnam, which gets a password
 * field that corresponds to the given user id.
 * 
 * 	-	For groups, a call to '$ apropos -s 3 "group.*name"' reveals to us the function getgrnam for getting
 * the id corrsponding to a group name. Notice that for the case the user does not supply a groupid, we set the
 * gid to -1.
 * 
 * Recall that to change the owner or group, we need to be root. Indeed, we can check this by the getuid and
 * then return if it's not 1. Note, however, that this is not necessary, and the code catches this error by 
 * itself. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
   if (getuid() != 0){
	   fprintf(stdout, "You need to be super user to execute this command.\n");
	   return 1;
   }

   char *username = { 0 }; /* extracted username */
   char *groupname = { 0 }; /*extracted groupname*/
   
   /* Check that the user supplied two arguments (filename and user or user:group) */
   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s [user][:group]" 
         " [path]\n", argv[0]);
      return 1;
   }

   /* Extract username and groupname */
   username = strtok(argv[1], ":");
   groupname = strtok(NULL, ":");


   struct passwd *user; /* struct for getpwnam */
   unsigned int uid; /* extracted UID/GID */
   if ( (user = getpwnam(username)) == NULL )
   {
      fprintf(stderr, "Invalid username\n");
      return 1;
   }

   struct group *grp; /* struct for getgrnam */
   unsigned int gid;
   uid = user->pw_uid; /* get the UID */
   if (groupname != NULL) /* if we typed a group */
   {
      if ( (grp = getgrnam(groupname)) == NULL )
      {
         fprintf(stderr, "Invalid groupname\n");
         return 1;
      }
      gid = grp->gr_gid; /* get the GID */
   }
   else
   {
      /* if no group is specifed, -1 won't change 
         it (man 2 chown) */
      gid = -1;
   }

   /* update user/group (argv[2] is the filename)*/
   if ( chown(argv[2], uid, gid) == -1 )
   {
      perror("Can't change owner/group");
      return 1;
   }

   return 0;
}
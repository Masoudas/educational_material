/**
 * In this program, we shall extract some of the innode information of a file. 
 * 
 * First question is, which headers contains the information we seek? Well, as we want to get file stats,
 * typing 'man 3 stat' tells us that we should look into 'sys/stat'. Now, if we follow the "see also
 * section," we find that we have essentially three functions:
 * 	-	stat:	 Follows symbolic links.
 * 	-	lstat:	 Does not follow symbolic links.
 * 	-	fstatat: Depending on the flag we pass to it, it would be equivalent to either of the above 
 * 				 functions.
 * 
 * A note on the node value: If we print the mode as shown below, we see that it contains the entirety of
 * what is printed with ls -l. Hence, the left-most bit actually determines whether the given file is a
 * regular file, symlink, etc. In fact, we have the following macros to check for the file type:
 * 
 
 	   S_IFSOCK   0140000   socket
       S_IFLNK    0120000   symbolic link
       S_IFREG    0100000   regular file
       S_IFBLK    0060000   block device
       S_IFDIR    0040000   directory
       S_IFCHR    0020000   character device
       S_IFIFO    0010000   FIFO

 * Note: The first values of the file_mode are further discussed in "man 7 inode." For example, 100775 means a
 * folder (10,) with 0755 permission. In fact, here's the table:
 
 14   socket
 12   symbolic link
 10   regular file
 06   block device
 04   directory
 02   character device
 01   FIFO
 
 * 
 * Below for example, I used the lstat function to make sure that links are not followed (joone ammam!)
 * 
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/file.h>
#include <errno.h>
#include <stdio.h>


int main(int argc, char* argv[]){
	if (argc < 2) return 0;

	struct stat file_stat;

	if(lstat(argv[1], &file_stat) == -1){
		perror("Can't get file stat");
		return 1;
	}

	fprintf(stdout, "File: %s\n", argv[1]);
	fprintf(stdout, "Size: %li		Blocks: %li",
		file_stat.st_size, file_stat.st_blocks);
	
	if (S_ISLNK(file_stat.st_mode) != 0){
		fprintf(stdout, "		Symbolic link\n");
	} else{	// Didn't feel like checking all conditions for block, char, etc.
		fprintf(stdout, "		Regular file\n");
	}

	return 0;
}
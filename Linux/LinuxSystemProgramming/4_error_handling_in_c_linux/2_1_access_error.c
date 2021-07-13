/**
 * In this example, we try and create a file in the path specified by the user. Notice the use of MAX_PATH in the 
 * linux/limits header, which determines the allowable path length on this system. 
 * 
 * The 'creat' function in the 'fcntl' header creates a file for us. Notice that the second parameter mod_t determines (like
 * chmod) the mod of the file. Aha! Very important to note that the mode is defined as 00644. Why? Because it should be
 * in octal format, hence it has an extra leading zero! Note that creat is a system call, because it's in the linux
 * header.
 * 
 * Now, consider giving this program /file.txt. In my distro we don't see any error. We need then to check the return
 * value of this command to check if the file was made or not, which is what we do next.
 */

#include <stdio.h>
#include <linux/limits.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		printf("No file name was supplied\n");
		return 1;
	}

	char path[PATH_MAX] = {'\0'};
	strncpy(path, argv[1], PATH_MAX-1);

	creat(path, 00644);

	return 0;
}
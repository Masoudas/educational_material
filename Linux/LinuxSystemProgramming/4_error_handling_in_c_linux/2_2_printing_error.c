
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

	if (creat(path, 00644) == -1){
		fprintf(stderr, "Can't create file %s\n", path);
 	    return 1;
	}

	return 0;
}
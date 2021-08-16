/**
 * As we already know, when the linux processes start, the getty is replaced with the login program to allow for
 * log in. We can use execl function to do such task, and for example change our current program with a new one.
 * The function is in the unistd header, and has the following signature (note that there are other versions for
 * passing environment variables, and etc):

int execl(const char *pathname, const char *arg, //(char  *) NULL// );

 * Note that execl takes four mandatory arguments. First is the program path, second is program name, third is
 * the arguments we want to pass (here it was file name,) which needs not to be confined to one argument. Finally,
 * we MUST pass a (char*)NULL to indicate the termination of arguments.
 * 
 * For example below, we read the password file by calling the less binary. The interesting point here is that
 * if we check the pstree of this process in another terminal, we see how the process command changes when 
 * reaching the execl command. It's quite interesting!
 * 
 * Hence, essentially we replace the executable inside a process with execl.
 */


#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
	printf("The pid is %i:\n", getpid());

	getchar();

	printf("Executing /usr/bin/less...\n");
	if( execl("/usr/bin/less", "less", "/etc/passwd", (char*)NULL) == -1 ){
		perror("Can't change executable");
	}

	return 0;
}
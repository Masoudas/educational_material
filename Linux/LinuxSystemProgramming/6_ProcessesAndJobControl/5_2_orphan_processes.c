/**
 * An orphan is a child whose parent has died. However, as we have learned in this chapter, every process needs a 
 * parent process. So, even orphans need a parent process. To solve this dilemma, every orphan gets inherited by 
 * systemd, which is the first process on the system—PID 1.
 * 
 * A side note is that systemd in my Linux distro actually creates a subprocess and then that subprocess inherits
 * this orphan.
 * 
 * Don't forget that to see the parent and status of this process, we can also use:
 
$ ps jp 13894

 */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char** argv){
	__pid_t parent = getpid();
	printf("Parent PID is: %i\n ", parent);

	__pid_t orphan = fork();

	if (orphan == 0){
		printf("Inside child process\n");
		sleep(60);
	} else if ( orphan > 0){
		printf("Child process is %i\n", orphan);
		sleep(20);
		printf("Goodbye\n");
		return 0;
	} else {
		perror("Could not work process!\n");
	    return 1;
	}

	return 0;

}
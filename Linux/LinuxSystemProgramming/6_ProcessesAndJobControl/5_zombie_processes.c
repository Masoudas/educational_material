/**
 * In this section, we shall discuss zombie processes Creating a zombie process is in fact rather 
 * easy, and we just don't wait for the child process with waitpid.
 * 
 * Me: note that zombies are different from daemons I guess. A zombie process exists before its parent checks
 * for its status and waits on it. Why should we care about this? 
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	__pid_t parent = getpid();
	fprintf(stdout, "PID of parent is %d\n", parent);

	__pid_t pid = 0;
	if ( (pid = fork()) == -1){
		perror("Can't create the process\n");
		return 1;
	}

	if (!pid){
		/* if pid is 0 we are in the child process */
      	printf("Hello and goodbye from the child!\n");    	
		exit(0);

      	/* if pid is greater than 0 we are in  the parent */
	    printf("Hello from the parent process! My child had PID %d\n", pid);
        sleep(120);
	} else{	 // Notice that the parent process does not wait for the child to terminate.
		fprintf(stderr, "Something went wrong with forking\n");
        return 1;
	}

}
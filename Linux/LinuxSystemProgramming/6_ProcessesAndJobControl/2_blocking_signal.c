/**
 * There's a way to block the stop signal (when pressing the Ctrl+Z, which sends the program to background and
 * frozen), as well as blocking the kill (or interrupt) signal (with Ctrl+C), and in general any signal directly. 
 * 
 * To that end, we can use the sigprocmask function. This function is used for examining and changing blocked
 * signals. The signature is:

int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset) 

 * It's pretty much like the sigaction function. The how parameter is ike the sigaction, and as such needs no
 * further discussion. 
 * 
 * Now, to create a signal set, the approach that we use is to create an empty set with the sigemptyset function,
 * and then we add the signals we want to block to it, using the method sigaddset.
 * 
 * Just as a reminder, note that sigismember is another function, which can be used to determine whether a signal
 * is a member or not.
 */

#define _POSIX_C_SOURCE 200809L	

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	sigset_t set;
	
	sigemptyset(&set);
	sigaddset(&set, SIGINT);	// Block the kill signal. At this point, this program can't be terminated.
								// SIGINT is the interrupt CTRL+C signal.

//	sigprocmask(SIG_BLOCK, &set, NULL);

	/* infinite loop to keep the program running */
	char a[20];
    for (int i = 0; i < 10; i++)
    {
		fprintf(stdout, "Try blocking the program. I dare you!\n");
		fscanf(stdin, "%s", a);
        sleep(2);
    }

	sigprocmask(SIG_UNBLOCK, &set, NULL);	// We should unblock the signal after certain tries, otherwise we won't
											// able to terminate the program.
							
	return 0;
}

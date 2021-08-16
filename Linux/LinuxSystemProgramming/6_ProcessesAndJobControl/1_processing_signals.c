/**
 * The intend of this program is to process various signals differently, including the kill signal, or stop
 * signal.
 * 
 * Because processing signals is not C99, we strictly specifu the POSIX version in the following code.
 * 
 * The header that contains the signal processing methods is signal.h In it, there exists the macros that correspond
 * to signal values. To register an action with a signal, we use the sigaction method, whose signature is:

int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);

 * the first parameter is signal. The second parameter is the actions to be taken on receipt of the signal. The
 * third is used to copy the action previosuly associated with the signal.
 * 
 * The sigaction structure has the following structure:

Type:					Name		Description:
void(*) (int)	***	sa_handler	***	Pointer to a signal-catching function or one of the macros SIG_IGN or SIG_DFL.
sigset_t		***	sa_mask		***	Additional set of signals to be blocked during execution of signal-catching function.
int				***	sa_flags	***	Special flags to affect behavior of signal.
void(*) (int, siginfo_t *, void *))  *** sa_sigaction  *** Pointer to a signal-catching function. │
      
 * Now, below we've created simple handlers. Note that sa_mask below is set to all functions! This implies that all
 * other signals will be ignored when our particular signal is being handled! T do so, we use the function called
 * sigfillset. Then, we set sa_flags to SA_RESTART, meaning any interrupted systemcall will be restarted (jeez!).
 * As such, we can set a handler for our signal. Notice that we never set the sa_sigaction parameter.
 * 
 * To use this code, send the process to background, and then send signals to it:
 
$ ./prog &
$ kill -USRSIG1 PID_NUMBER
Received USR2 signal
 */

#define _POSIX_C_SOURCE 200809L		// This is very important when writing and compiling, otherwise signal header
									// content won't appear.

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

// The signal handler to be called upon receiving a signal in this process.
void SIGUSR1_Handler(int sig);
void SIGUSR2_Handler(int sig);

int main(void)
{
	pid_t pid; /* to store our pid in */
	pid = getpid(); /* get the pid */
	
	printf("Program running with PID %d\n", pid);

	// Register handler for SIGUSR1	
	/* prepare sigaction() */
	struct sigaction action; /* for sigaction */
	action.sa_handler = SIGUSR1_Handler;
	sigfillset(&action.sa_mask);
	action.sa_flags = SA_RESTART;

	/* register two signal handlers, one for USR1 and one for USR2 */
	sigaction(SIGUSR1, &action, NULL);
	
	// Register handler for SIGUSR1	
	/* prepare sigaction() */
	struct sigaction action1; /* for sigaction */
	action1.sa_handler = SIGUSR2_Handler;
	sigfillset(&action1.sa_mask);
	action1.sa_flags = SA_RESTART;

	/* register two signal handlers, one for USR1 and one for USR2 */
	sigaction(SIGUSR2, &action1, NULL);
	
	/* infinite loop to keep the program running */
	for (;;)
	{
		sleep(10);
	}

	return 0;
}

void SIGUSR1_Handler(int sig)
{
	printf("Received USR1 signal\n");
}

void SIGUSR2_Handler(int sig)
{
	printf("Received USR2 signal\n");
}
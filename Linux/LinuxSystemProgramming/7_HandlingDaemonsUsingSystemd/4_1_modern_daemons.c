/**
 * Daemons that are handled by systemd don't need to fork or close their file descriptors. Instead, it's advised to 
 * use standard output and standard error to write the daemon's logs to the journal. The journal is systemd's 
 * logging facility.
 * 
 * An example of such daemon is given below. Notice that there's no forking in this program, and everything as said
 * is written to the stdout, stdin and stderr.
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void sigHandler(int sig);
int main(void)
{
    time_t now; /* for the current time */
    struct sigaction action; /* for sigaction */
    /* prepare for sigaction */
    action.sa_handler = sigHandler;
    sigfillset(&action.sa_mask);
    action.sa_flags = SA_RESTART;
    /* register the signal handler */
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGHUP, &action, NULL);

    for (;;) /* main loop */
    {
        time(&now); /* get current date & time */
        printf("Daemon alive at %s", ctime(&now));
        fflush(stdout);
        sleep(30);
    }
    return 0;
}

void sigHandler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Hello world!\n");
    }
    else if (sig == SIGTERM)
    {
        printf("Doing some cleanup...\n");
        printf("Bye bye...\n");
        exit(0);
    }
    else if (sig == SIGHUP)
    {
        printf("HUP is used to reload any " 
            "configuration files\n");
    }
} 
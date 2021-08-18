/**
 * Note that the deamon code we wrote in the previous section has a flaw, in that after the daemon terminates,
 * we don't clean up the pid or the log file.
 * 
 * We can remedy this by taking providing signal handlres that would be executed after when a SIGKILL, or SIGINT
 * or SIGTERM is sent to the process.
 */
???
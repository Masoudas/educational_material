/**
 * A daemon is a background process that runs on the system and performs some tasks. 
 * 
 * The essential point in creatin a daemon is to create a process that has no parent other than systemd, and to
 * also change its session id, so that it wouldn't be killed by its session id (could be a terminal or log 
 * session.)
 * 
 * So, here are the steps we need to take:
 * 	-	Create an orphan.
 * 	-	Set a new session in the child process (using setsid()), to make the forked process a session leader. This
 * 		will detach our process from any terminal, so that it wouldn't exit when a terminal might.
 *  -	Fork the process again, to create a grand child process. As such, we won't have a session leader. 
 * 		The reason for forking the second time is that a session leader—which is what our first child after the 
 * 		setsid() call is—can acquire a new controlling terminal if it were to open a terminal device. When we do 
 * 		the second fork, that new child is just a member of the session that was created by the first child, not 
 * 		the leader, and hence it cannot acquire a controlling terminal anymore. The reason for avoiding a 
 * 		controlling terminal is that if that terminal would exit, so would the daemon. Forking twice when creating 
 * 		a daemon is often called the double-fork technique.
 * 	-	Set the umask of the child process to something sensible (umask sets the default file creation mode for
 * 		subsequent executions. For example umask(022)), meaning don't let write for group and others.
 * 	-	We change the pwd to "/", so that this daemon wouldn't stop file systems from unmounting, or folders from
 * 		getting deleted (Say what?)
 * 	- 	Because this daemon is detached from a terminal, keeping stdin, stdout or stderr is pointless. Therefore,
 * 		we close their file streams using fclose. This is important because otherwise writing to them might cause
 * 		a crash. (how about file streams?)
 * 	-	Because other programs might use these file descriptors to write to them or read, we need to reopen 
 * 		file descriptors 0, 1, 2. Note that just opening anything with a descriptor would be fine, because
 * 		the indexing by default starts from 0 if no other file descriptors exist (so we should be cautious not
 * 		to have any other opened.) What should we open then? Well, we can open /dev/null.
 * 		Question: What if someone uses stdout, stdin or stderr file streams? Well, to avoid that, we can just
 * 		close them.
 * 
 * Next, we shall implement the above mentioned strategy in practice.
 * 
 * Checkout 'man 7 daemon' for more information on daemons.
 */
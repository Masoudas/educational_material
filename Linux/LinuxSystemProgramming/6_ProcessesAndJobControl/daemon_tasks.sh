echo "Daemon id is: " $$

umask 022 
cd "/"

while true; do
	echo "Shell-made daemon is alive at " $(date) >> "/tmp/my-daemon-is-alive.txt"
	sleep 10
done
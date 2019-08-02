

Task 1: A Process creates a child process. Child process should print out "hello 0" "hello 1". , etc... 1 line per second. After a certain number of seconds (user input), 
the parent process should kill the child process WITH signal mechanism ONLY, don't use exit() on the child. You can use alarm() which may show the "Alarm clock". (Alarm clock may not appear depending on your environment. It is not required).
There should be one parent process and one child process only.

Task 2 :using the signal mechanism system call (don't use wait() or pipe(), you may still need sleep()). 
You can still write or read to the disk. You should have one parent process and one child process only.
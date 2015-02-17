#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char* argv[]){
	// Create child process
	pid_t pid = fork();

	// Child code
	if (pid == 0){
		// Use getpid() and getppid() to retrieve 
		// child pid and parent pid respectively
		printf("	ex 2 : child %d of parent : %d\n", (int)getpid(), (int)getppid());
		// The child processus doesn't stop
		while(1){ }
	// Parent code
	}else {
		// Parent process sleeps 10 seconds
		// You can verify that your child process 
		// is still atached to his parent with
		// the 'ps' command line
		sleep(10);

		// Parent kills the child before exiting
		printf("	ex 2 : killing child process %d \n", pid);
		kill(pid, SIGUSR1);
	}
	return 0;
}

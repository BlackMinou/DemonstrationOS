#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char* argv[]){

	//Create the child process with fork()
	pid_t pid = fork();

	// Child code
	if (pid == 0){	
		// The child processus doesn't stop
		while(1){ }
	// Parent code
	}else {
		int status;
		// Parent waits for the child to finish
		waitpid(pid, &status, 0);
	}
	return 0;
}

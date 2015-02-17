#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char* argv[]){
	pid_t pid = fork();
	if (pid == 0){
		printf("ex 3 : launching exercice 2 program ... \n");
		execve("exercice2", NULL, NULL);
	}else {
		int status;
		// Wait for the exercice 2 launched by child to end
		waitpid(pid, &status, 0);
		printf("ex 3 : exiting\n");
	}
	return 0;
}

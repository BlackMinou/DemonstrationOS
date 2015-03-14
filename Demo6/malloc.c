#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){
	char* s = malloc(15);
	strcpy(s, "malloc test");
	if(s == NULL){
		printf("%s\n", strerror(errno));
	}else {
		printf("%s\n", s);
		free(s);
	}

	exit(EXIT_SUCCESS);
}

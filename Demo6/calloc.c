#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){
	char* s = calloc(15, sizeof(char));
	strcpy(s, "calloc test");
	if(s == NULL){
		printf("%s\n", strerror(errno));
	}else {
		printf("%s\n", s);
		free(s);
	}

	exit(EXIT_SUCCESS);
}

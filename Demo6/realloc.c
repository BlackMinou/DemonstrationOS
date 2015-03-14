#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){

	char* s = malloc(15);
	if(s == NULL){
		printf("%s\n", strerror(errno));
	}else {
		memcpy(s, "malloc", 21);
		printf("%s\n", s);
	}

	s = realloc(s, 20);
	if(s == NULL){
		printf("%s\n", strerror(errno));
	}else {
		memcpy(s, "malloc", 21);
		printf("%s\n", s);
		strcat(s, ", reallocated");
		printf("%s\n", s);
	}
	free(s);	

	exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* readfile(void* path)
{
	FILE* f = fopen(path, "r");
	char* buff = calloc(sizeof(char), 50);
	fgets(buff, 50, f);
	fclose(f);
	pthread_exit(buff);
}

int main (int argc, char *argv[]){
	pthread_t t1, t2, t3;
	void* r1, *r2, *r3;
	pthread_create(&t1, NULL, readfile, argv[1]);
	pthread_create(&t2, NULL, readfile, argv[2]);
	pthread_create(&t3, NULL, readfile, argv[3]);
	pthread_join(t1,&r1);
	pthread_join(t2,&r2);
	pthread_join(t3,&r3);
	printf("%s%s%s", r1, r2, r3);
}




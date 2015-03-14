#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

// Struct used for exercice 2
typedef struct {
    char* first_name;
    char* name;
}Person;

void deallocate_person(Person* p){
	free(p->first_name);
	free(p->name);
	free(p);
}

// freeing memory with realloc
void test1(){
	char* s = malloc(25);
	strcpy(s, "malloc test");
	strcat(s, "zblahhhh");

	s = realloc(s, 0);
	printf("%s\n", s);
}

//trying to free literals
void test2(){
	char* str = "efergeebhe";
	free(str);
}

// not deallocating memory ...
void test3(){
	for(int i = 0; i < 10000000; i++){
		char* string = malloc(1000);
	}
	sleep(15);
}

//test3 but with deallocation ! 
void test4(){
	for(int i = 0; i < 10000000; i++){
		char* string = malloc(1000);
		free(string);
	}
	sleep(15);
}

//Structure allocation and deallocation n1
void test5(){
	Person* p = malloc(sizeof(Person));
	p->first_name = malloc(20);
	p->name = malloc(20);
	strcat(p->first_name, "Prenom");
	strcat(p->name, "Nom");

	printf("%s  %s  \n", p->first_name, p->name);

	free(p);

	printf("%s  %s  \n", p->first_name, p->name);
}

//Structure allocation and deallocation n2
void test6(){
	Person* p = malloc(sizeof(Person));
	p->first_name = malloc(20);
	p->name = malloc(20);
	strcat(p->first_name, "Prenom");
	strcat(p->name, "Nom");

	printf("%s  %s  \n", p->first_name, p->name);

	p = realloc(p, 0);

	printf("%s  %s  \n", p->first_name, p->name);
}

//Structure allocation and deallocation n1
void test7(){
	Person* p = malloc(sizeof(Person));
	p->first_name = malloc(20);
	p->name = malloc(20);
	strcat(p->first_name, "Prenom");
	strcat(p->name, "Nom");

	printf("%s  %s  \n", p->first_name, p->name);

	deallocate_person(p);

	printf("%s  %s  \n", p->first_name, p->name);
}

int main(int argc, char* argv[]){
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	test5();
	exit(EXIT_SUCCESS);
}

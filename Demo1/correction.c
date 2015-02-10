#include <stdio.h>
#include <stdlib.h>
#include<dirent.h>
#include <sys/stat.h>
#include<string.h>

// Struct used for exercice 2
typedef struct {
    char first_name[20];
    char name[20];
    int age;
}Person;


// Ex1 : Read user's entries till there is no more entries
// and write them to a file
void write_file(char* filename){
    //Used to stock stdin values
    char buff[50];
    
    // Open the file
    FILE* f = fopen(filename, "w");
    
    // If the creation of the file failed, print an error and quit
    if(f == NULL){
	printf ("Error while creating the file %s \n", filename);
	return;
    }

    // read stdin with fgets
    while (fgets(buff, 50, stdin) != NULL){
	// break if buff contains only '\n',
	// which means he finished writing
        if (buff[0] == '\n') break;

	// Write buff into the file
        fprintf(f, buff);
    }
    // Important, don't forget to close the file
    fclose(f);
}

// Ex2 : Writes struct into a binary file
void binary_write(){

    // Create the file
    FILE* f = fopen("persons", "w");

    // Create multiple struct Person
    Person p1 = {"Romain", "Chanoir", 22};
    Person p2 = {"Lucas", "Bajolet", 24};
    Person p3 = {"Mathnieu", "Schmitt", 27};

    // Write previously created persons in the file
    fwrite(&p1, sizeof(Person),1,  f);
    fwrite(&p2, sizeof(Person),1,  f);
    fwrite(&p3, sizeof(Person),1,  f);

    // Again, dont forget to close the file
    fclose(f);
}

// Ex2 : Reads struct from a binary file
void binary_read(){
    FILE* f = fopen("persons", "r");

    // Place the cursor at the begining of the file
    // after the first person
    fseek(f, sizeof(Person), SEEK_SET);
    Person p;

    // Read a person from the actual position
    fread(&p, sizeof(Person), 1, f);
    fclose(f);

    // Print person's infos
    printf("%s, %s, %d\n", p.first_name, p.name, p.age);
}

// Ex 3 : Lists directory's content
void list_dir(char* dir_name){

    // Entry of a directory
    struct dirent* dp;

    // Directory representation
    DIR* d = opendir(dir_name);

    // If opendir failed, print an error and returns
    if(d == NULL){
	printf("Error, wrong dir name:  %s \n", dir_name);
	return;
    }else {
	// Read all the entry of the directory
    	while((dp = readdir(d)) != NULL){
		
		// Concat the dir name with the 
		// name of the current entry
        	char* nm = calloc(250,1);
        	int off = strlen(dir_name);
        	memmove(nm, dir_name, off);
        	memmove(nm + off, "/", 1);
        	off++;
        	memmove(nm+off, dp->d_name, strlen(dp->d_name));
        	
		// Open current entry as a file for reading
		FILE* f = fopen(nm, "r");
        	
		// Structure that contains the stats of the file
		struct stat buf;

		// Get the stats of the file
		int fd = fileno(f);
		fstat(fd, &buf);

		// If this is a directory : continue
		if(S_ISDIR(buf.st_mode)){
			printf("%s, is a directory, continue\n", nm);
			fclose(f);
		}else {

		// If this is a file, print it's stats
		// here we use only 2 stats, there is
		// plenty more if we want to use them
        		printf("Name : %s \n", nm);
        		printf("Size :  %d \n", buf.st_size);
        		printf("Last modified : %d \n", buf.st_mtime);
        		fclose(f);
		}
    	}
	// Close the directory
    	closedir(d);
    }
}

// Principal function that calls every others
int main(int argc, char *argv[])
{

    binary_write();
    binary_read();
    if (argc > 1){
	// Can't do exercice 1 and 3 at the same time
	// so one of theses two line must be commented
	// for the test
        list_dir(argv[1]);
        //write_file(argv[1]);
    }
    return 0;
}



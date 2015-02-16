#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qsrt(int* arr, int lb, int rb);
int part(int* arr, int lb, int rb);
void swap(int* arr, int l, int r);

int main(char* argc, int argv){
	int* arr = calloc(sizeof(int), 100000000);
	int i;
	srand(time(NULL));
	for(i = 0; i < 100000000; i++){
		arr[i] = rand() % 100000000;
	}
	qsrt(arr, 0, 99999999);
	for(i = 1; i < 100000000; i++){
		if(arr[i] < arr[i - 1]){
			printf("Error on sorted array, %d < %d at position %d\n", arr[i], arr[i + 1], i);
			return -1;
		}
	}
	return 0;
}

void qsrt(int* arr, int lb, int rb){
	if(lb >= rb) return;
	int p = part(arr, lb, rb);
	qsrt(arr, lb, p - 1);
	qsrt(arr, p + 1, rb);
}

int part(int* arr, int lb, int rb){
	int piv = rb;
	int st_ind = lb;
	int i;
	for(i = lb; i < rb; i++){
		if(arr[i] < arr[piv]){
			swap(arr, i, st_ind);
			st_ind ++;
		}
	}
	swap(arr, piv, st_ind);
	return st_ind;
}

void swap(int* arr, int l, int r){
	int tmp = arr[l];
	arr[l] = arr[r];
	arr[r] = tmp;
}

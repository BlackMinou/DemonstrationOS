#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void* qsrt(void* data);
void seq_qsrt(int* arr, int lb, int rb);
int part(int* arr, int lb, int rb);
void swap(int* arr, int l, int r);

typedef struct qsrt_data_th_t{
	int* arr;
	int lb;
	int rb;
} qsrt_data_th_t;

int main(char* argc, int argv){
	int* arr = calloc(sizeof(int), 100000000);
	int i;
	srand(time(NULL));
	for(i = 0; i < 100000000; i++){
		arr[i] = rand() % 100000000;
	}
	qsrt_data_th_t data;
	data.arr = arr;
	data.lb = 0;
	data.rb = 99999999;
	pthread_t t;
	pthread_create(&t, NULL, qsrt, &data);
	pthread_join(t, NULL);
	for(i = 1; i < 100000000; i++){
		if(arr[i] < arr[i - 1]){
			printf("Error on sorted array, %d < %d at position %d\n", arr[i], arr[i + 1], i);
			return -1;
		}
	}
	return 0;
}

void* qsrt(void* data){
	qsrt_data_th_t* d = (qsrt_data_th_t*)data;
	int* arr = d->arr;
	int lb = d->lb;
	int rb = d->rb;
	if(rb - lb < 200000){
		seq_qsrt(arr, lb, rb);
		pthread_exit(NULL);
	}
	pthread_t t1, t2;
	if(d->lb >= d->rb) pthread_exit(NULL);
	int p = part(d->arr, d->lb, d->rb);
	qsrt_data_th_t d1, d2;
	d1.arr = arr;
	d1.lb = d->lb;
	d1.rb = p - 1;
	d2.arr = arr;
	d2.lb = p + 1;
	d2.rb = d->rb;
	pthread_create(&t1, NULL, qsrt, &d1);
	pthread_create(&t2, NULL, qsrt, &d2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_exit(NULL);
}

void seq_qsrt(int* arr, int lb, int rb){
	if(lb >= rb) return;
	int p = part(arr, lb, rb);
	seq_qsrt(arr, lb, p - 1);
	seq_qsrt(arr, p + 1, rb);
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

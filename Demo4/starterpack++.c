#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_MONEY 5000
#define NB_SPENDINGS 5
#define AVERAGE_SPENDING 1000
#define NB_EARNINGS 2
#define EARNING 1000

// Remark : Randomness needs to be improved !


typedef struct{
	int money;
	int broke;
	pthread_t control_thread;

	pthread_t thread_spendings[NB_SPENDINGS];
	pthread_t thread_earnings[NB_EARNINGS];


}money;

static money account =
{
	.money = INITIAL_MONEY,
	.broke = 0,
};

static int rdm(int value){
	srand(time(NULL));
	return (rand() % value) + 1;
}


void* spend_money(void* data)
{
	while(1){

		sleep(rdm(5));
		if(account.broke) break;
		int val = rdm(AVERAGE_SPENDING);

		account.money = account.money - val;
		printf("Spending %d, %d left ! \n", val, account.money);
	}
	pthread_exit(NULL);
}

void* earn_money(void* data)
{
	while(1){

		sleep(rdm(5));
		if(account.broke) break;
		account.money = account.money + EARNING;
		printf("Earning %d, %d now in the account ! \n", EARNING, account.money);
	}
	pthread_exit(NULL);
}

void* manage_money(void* data){
	while(1){
		if(account.money <= 0){
			printf("You're completely broke, we're closing your account ! \n Bye Bye !\n");
			account.broke = 1;
			break;
		}
	}
	pthread_exit(NULL);
}


int main (int argc, char *argv[]){
	printf("starting program ...\n");

	int i = 0;

	int ret = pthread_create(&account.control_thread, NULL, manage_money, NULL);
	if(ret){
		fprintf(stderr, "%s", strerror(ret));
	}


	for(i = 0, i ; i < NB_SPENDINGS; i++){
		int ret = pthread_create(&account.thread_spendings[i], NULL, spend_money, NULL);
		if(ret){
			fprintf(stderr, "%s", strerror(ret));
		}
	}

	for(i = 0; i < NB_EARNINGS; i++){
		int ret = pthread_create(&account.thread_earnings[i], NULL, earn_money, NULL);
		if(ret){
			fprintf(stderr, "%s", strerror(ret));
		}
	}


	pthread_join(account.control_thread, NULL);
	return EXIT_SUCCESS;
};

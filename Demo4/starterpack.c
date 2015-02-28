#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// Variables for the execution, have fun and change them to test different cases !
#define INITIAL_MONEY 5000
#define NB_SPENDINGS 10
#define AVERAGE_SPENDING 500
#define NB_EARNINGS 2
#define EARNING 1000

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

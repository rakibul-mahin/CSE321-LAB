#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

int check = 1;

void *block(void *arg) {
	int k = *(int *)arg;
	for (int j=0; j<5;j++) {
		printf("Thread %d prints %d \n",k,check);
		check++;
	}
}

int main () {
	pthread_t thread[5];
	for (int i=0; i<5;i++) {
		pthread_create(&thread[i],NULL, block, &i);
		pthread_join(thread[i],NULL);
	}
}


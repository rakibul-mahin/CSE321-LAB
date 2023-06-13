#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

int var = 0;
void* block(void* arg) {
	var++;
}

int main () {
	pthread_t thread[5];
	for (int i=0; i<5;i++) {
		pthread_create(&thread[i],NULL, block, NULL);
		printf("thread-%d running \n",i+1);
		pthread_join(thread[i],NULL);
		printf("thread-%d closed \n",i+1);
	}
	
	return 0;
}


#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX 10
#define BUFLEN 6
#define NUMTHREAD 2

void *consumer(void *arg);
void *producer(void *arg);

char buffer[BUFLEN];
char source[BUFLEN];

int producerCount = 0;
int consumerCount = 0;
int bufferLen;

pthread_mutex_t countMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;

int threadId[NUMTHREAD] = {0, 1};
int i = 0;
int j = 0;

int main() {

    pthread_t thread[NUMTHREAD];
    strcpy(source, "abcdef");
    bufferLen = strlen(source);

    // create two threads
    pthread_create(&thread[0], NULL, producer, &threadId[0]);
    pthread_create(&thread[1], NULL, consumer, &threadId[1]);

    for (int i = 0; i < NUMTHREAD; i++) {
        pthread_join(thread[i], NULL);
    }
    return 0;
}

// producer block
void *producer(void *arg) {

    for (i = 0; i < MAX; i++) {
        pthread_mutex_lock(&countMutex);

        int consumerCheck = (producerCount + 1) % BUFLEN;

        while (consumerCheck == consumerCount) {
            pthread_cond_wait(&nonEmpty, &countMutex);
        }

        int sourceIndex = producerCount % bufferLen;
        buffer[producerCount] = source[sourceIndex];
        printf("%d produced %c by Thread %d\n", i, buffer[producerCount], *((int *)arg));
        producerCount = (producerCount + 1) % BUFLEN;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&countMutex);
    }
}

// consumer block
void *consumer(void *arg) {

    for (j = 0; j < MAX; j++) {
        pthread_mutex_lock(&countMutex);

        while (producerCount == consumerCount) {
            pthread_cond_wait(&full, &countMutex);
        }

        printf("%d consumed %c by Thread %d\n", j, buffer[consumerCount], *((int *)arg));
        consumerCount = (consumerCount + 1) % BUFLEN;
        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&countMutex);
    }
}

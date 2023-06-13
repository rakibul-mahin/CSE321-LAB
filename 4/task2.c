#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ITEMS 5
#define BUFFER_SIZE 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;

char crops[BUFFER_SIZE]={'R','W','P','S','M'};
char warehouse[BUFFER_SIZE]={'N','N','N','N','N'};
pthread_mutex_t mutex;

void *producer(void *pno){
    for(int i=0; i<MAX_ITEMS; i++){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in]=crops[in];
        
        printf("Farmer %d: Insert crops %c at %d\n", *((int *)pno), warehouse[in], in); 
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        
        sem_post(&full);
    }
    
    printf("Farmer%d:", *((int *)pno));
    for(int g=0; g<BUFFER_SIZE; g++){
        printf(" %c", warehouse[g]);
    }
    printf("\n");
}

void *consumer(void *cno){
    for(int i=0; i<MAX_ITEMS; i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        char item = warehouse[out];
        
        printf("Shop Owner %d: Remove crops %c from %d\n", *((int *)cno), item, out);
        warehouse[out] = 'N';
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        
        sem_post(&empty);
    }
    
    printf("ShopOwner%d:", *((int *)cno));
    for(int w=0; w<BUFFER_SIZE; w++){
        printf(" %c", warehouse[w]);
    }
    
    printf("\n");
}

int main(){
    pthread_t farm[5], shop[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    int a[5] = {1, 2, 3, 4, 5};
    
    for(int i=0; i<5; i++){
        pthread_create(&farm[i], NULL, (void *)producer, (void *)&a[i]);
    }
    
    for(int i=0; i<5; i++){
        pthread_create(&shop[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    
    for(int i=0; i<5; i++){
        pthread_join(farm[i], NULL);
    }
    
    for(int i=0; i<5; i++){
        pthread_join(shop[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}

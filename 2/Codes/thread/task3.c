#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>
#include <string.h>

int i = 0;
int lin[2];

void* add_ascii(void *ptr) {
	char line[500];
    	printf("Enter a string: ");
    	fgets(line, sizeof(line), stdin);
    	int sum = 0;
    	for(int i=0; line[i]!='\0'; i++){
    		sum += line[i];
    	}
    	lin[i] = sum;
    	i += 1;

}

int main(int argc,char* argv[]){
	pthread_t thread[2];
	for(int i=0; i<3;i++) {
		pthread_create(&thread[i], NULL, add_ascii, NULL);
		pthread_join(thread[i], NULL);
		
	}
	if (lin[0]==lin[1] && lin[1]==lin[2] && lin[0]==lin[2]){
		printf("Youreka\n");
	}
	else if(lin[0]==lin[1] || lin[1]==lin[2] || lin[0]==lin[2] ){
		printf("Miracle\n");
	}
	else { printf("Hasta la vista\n"); }
	
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int arr[argc-1];
	for(int i=0; i<argc-1; i++){
		arr[i] = atoi(argv[i+1]);
	}
	pid_t id;
	id = fork();
	if (id<0){
		printf("Faulty Code.\n");
	}else if (id == 0){
		int temp;
		for(int j=0; j<argc-1; j++){
			for(int k=j+1; k<argc-1; k++){
				if (arr[j]<arr[k]){	
					temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;
				}
			}
		}
		for(int m=0; m<argc-1; m++){
			printf("%d ", arr[m]);
		}
		printf("\n");
	}else{
		wait(NULL);
		for(int l=0; l<argc-1; l++){
			if (arr[l]%2==0){
				printf("%d is even\n", arr[l]);
			}else{
				printf("%d is odd\n", arr[l]);
			}
		}
	}
	return 0;
}

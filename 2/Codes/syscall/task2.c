#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t id1, id2;
	id1 = fork();
	
	if(id1 < 0){
		printf("Failed \n");
	}else if(id1 == 0){
		//This is the Child Process
		id2 = fork();
		if(id2 < 0){
			printf("Failed \n");
		}else if(id2 == 0){
			//This is another Child Process
			printf("I am grandchild \n");
		}else{
			//This is another Parent Process
			wait(NULL);
			printf("I am Child \n");
		}
	}else{
		//This is the Parent Process
		wait(NULL);
		printf("I am parent \n");
	}
	
	return 0;
}

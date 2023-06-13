#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int count= 3;

int main(){
	pid_t a = fork();
	pid_t b = fork();
	pid_t c = fork();
	if (a==0){
		if (b==0){
			if (c!=0){
				wait(NULL);
				if ((getpid()%2)==1){
					fork();
					count++;
					printf("%d",count);
				}
			}
		}
		else{
			wait(NULL);
			if ((getpid()%2)==1){
				count++;
				fork();
				printf("%d",count);
			}
		}
	}
	else{
		wait(NULL);
		if ((getpid()%2)==1){
		count++;
		fork();
		printf("%d",count);
		}
	}
	return 0;
}


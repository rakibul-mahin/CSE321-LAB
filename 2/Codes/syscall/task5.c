#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	pid_t c_pid, g_pid1, g_pid2,g_pid3;
	printf("1. Parent process ID: %d\n", getppid());

	c_pid = fork();
	if (c_pid < 0) {
		printf("Fork Failed");
	}else if (c_pid == 0) {
		//create 3 grandchild
		g_pid1 = fork();
		g_pid2 = fork();
		g_pid3 = fork();
		if (g_pid1 > 0 && g_pid2 > 0 && g_pid3 > 0){
			printf("3. Grand Child process ID: %d\n", g_pid1);
			printf("4. Grand Child process ID: %d\n", g_pid2);
			printf("5. Grand Child process ID: %d\n", g_pid3);
		}
	}else {
		printf("2. Child process ID: %d\n", c_pid);
		wait(NULL);
	}
	
	return 0;
}


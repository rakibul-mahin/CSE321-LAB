#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
    char buffer[100];
    FILE *fd;
    fd = fopen(argv[1], "a");
    int i = -1;
    while (i < 0){
        scanf("%s", buffer);
        if (strcmp(buffer, "-1")==0){    
            break;
        }else{    
            fprintf(fd, "%s \n", buffer);
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(){
    int i;
    char email[100];
    char *domain;
    printf("Enter email ID: ");
    scanf("%s", email);

    domain = strstr(email, "sheba.xyz");

    if (domain){
        printf("Email address is okay");
    }
    else{
        printf("Email address is outdated");
    }

    return 0;
}

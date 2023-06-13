#include <stdio.h>

void check_perfect(int num1, int num2){
    for(int i = num1; i <= num2; i++){
        int total = 0;
        for(int j = 1; j <= i - 1; j++){
            if(i % j == 0){
                total += j;
            }
        }
        if(total == i){
            printf("%d\n",i);
        }
    }
}

int main(){
    int start, end;
    printf("Enter first number: ");
    scanf("%d", &start);
    printf("Enter second number: ");
    scanf("%d", &end);
    check_perfect(start, end);

    return 0;
}
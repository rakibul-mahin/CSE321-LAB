#include <stdio.h>

int isPalindrome(char *str) {
    int i, len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    for(i = 0; i < len/2; i++) {
        if(*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if(isPalindrome(str)) {
        printf("Palindrome\n");
    }
    else {
        printf("Not Palindrome\n");
    }

    return 0;
}


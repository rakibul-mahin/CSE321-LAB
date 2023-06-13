#include <stdio.h>

int main() {
    char password[100];
    int len, lowercase, uppercase, digit, special;
    lowercase = uppercase = digit = special = 0;
    
    printf("Enter the password: ");
    scanf("%s", password);
    
    len = strlen(password);
    
    for(int i = 0; i < len; i++) {
        if(islower(password[i])) {
            lowercase = 1;
        }
        else if(isupper(password[i])) {
            uppercase = 1;
        }
        else if(isdigit(password[i])) {
            digit = 1;
        }
        else if(password[i] == '_' || password[i] == '$' || password[i] == '#' || password[i] == '@') {
            special = 1;
        }
    }
    
    if(!lowercase) {
        printf("Lowercase character missing, ");
    }
    
    if(!uppercase) {
        printf("Uppercase character missing, ");
    }
    
    if(!digit) {
        printf("Digit missing, ");
    }
    
    if(!special) {
        printf("Special character missing");
    }
    
    if(lowercase && uppercase && digit && special) {
        printf("OK\n");
    }
    
    return 0;
}

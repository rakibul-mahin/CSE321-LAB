#include <stdio.h>

int main(void) {
  int num1, num2, res;
  char op[1];
  
  printf("Enter Number1: ");
  scanf("%d",&num1);

  printf("Enter Number2: ");
  scanf("%d",&num2);

  printf("Enter Operation: ");
  scanf("%s",op);

  if(num1 > num2){
    res = sub(num1, num2);
    printf("Result: %d", res);
  }else if(num1 < num2){
    res = add(num1, num2);
    printf("Result: %d", res);
  }else if(num1 == num2){
    res = mul(num1, num2);
    printf("Result: %d", res);
  }
  return 0;
}

int add(int num1, int num2) {
  return (num1 + num2);
}

int sub(int num1, int num2) {
  return (num1 - num2);
}

int mul(int num1, int num2) {
  return (num1 * num2);
}

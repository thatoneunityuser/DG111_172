#include <stdio.h>

int main() {
  int num;
  printf("enter the number ");
  scanf("%d", &num);

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      printf("the number is not prime");
      return 0;
    }
  }
  if (num != 1) {
    printf("the number is prime");
  }
  return 0;
}
#include <stdio.h>

int main() {
  printf("Square pattern\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("Triangle pattern\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("Diamond pattern\n");
  int n = 3;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      printf(" ");
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= n - i; j++) {
      printf(" ");
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
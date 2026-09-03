#include <stdio.h>

int main() {
  for (int i = 1; i <= 10; i++) {
    printf("%d ", i);
  }

  int b = 1;
  while (b <= 10) {
    printf("%d ", b);
    b++;
  }

  int c = 1;
  do {
    printf("%d ", c);
    c++;
  } while (c <= 10);

  return 0;
}
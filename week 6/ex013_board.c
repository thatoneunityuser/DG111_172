#include <stdio.h>

int main() {
  int column = 3;
  int row = 5;
  int count = 1;
  for (int i = 0; i < column; i++) {
    for (int j = 0; j < row; j++) {
      printf("+---+ ");
    }
    printf("\n");
    for (int j = 0; j < row; j++) {
      printf(" %2d | ", count);
      count++;
    }
    printf("\n");
  }
  for (int j = 0; j < row; j++) {
    printf("+---+ ");
  }
  printf("\n");
  return 0;
}
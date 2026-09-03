#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int target = rand() % 100 + 1;
  int guess;
  int attempts = 0;
  printf("Guess the number between 1 and 100\n");
  scanf("%d", &guess);
  do {
    if (guess == target) {
      printf("Correct! You guessed the number in %d attempts\n", attempts);
      break;
    } else if (guess < target) {
      printf("Too low\n");
    } else {
      printf("Too high\n");
    }
    scanf("%d", &guess);
    attempts++;
  } while (guess != target);
  return 0;
}

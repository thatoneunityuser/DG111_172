#include <stdio.h>

int main() {
  int current_hp = 99;
  int Max_Hp = 100;
  int Potion_Amount = 3;

  printf("%d / %d \n", current_hp, Max_Hp);

  while (current_hp < Max_Hp) {
    if (Potion_Amount > 0) {
      Potion_Amount--;
      printf("you use a potion now you have %d \n", Potion_Amount);
      current_hp += 20;
      if (current_hp >= Max_Hp) {
        current_hp = Max_Hp;
        printf("hp is full \n");
        printf("%d / %d \n", current_hp, Max_Hp);
        break;
      }
      printf("%d / %d \n", current_hp, Max_Hp);

    }

    else {
      printf("you don't have a potion \n");
      break;
    }
  }

  return 0;
}
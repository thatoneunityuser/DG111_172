#include <stdio.h>

int main() {
  int level = 4;
  int baseDamage = 12;
  int bonus = level * 3;
  float finalDamage = (baseDamage + bonus) / 2.0;
  printf("finalDamage = %.1f\n", finalDamage);

  return 0;
}
// final damage ควรจะเป็น  12.0f
// เหตุผล เราประกาศออกมาเป็น float

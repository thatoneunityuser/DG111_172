#include <stdio.h>

int main() {
  // กติกา: การต่อสู้ควรจบทันทีที่ hp <= 0
  int hp = 16;
  int rounds = 0;
  while (rounds < 5) {
    hp -= 4;
    printf("Round %d: hp = %d\n", rounds, hp);
    if (hp <= 0) {
      printf("Player down!\n");
      break;
    }
    rounds++;
  }
  return 0;
}
// 1 จุดที่ผิดกติกา คือ if(hp = 0 , มันควรเป็น <=0 )
// 2  จุดที่ทำให้ผิดกติกา คือ while (round < 5 ) ต่อให้ตาย เกมก็ยังดำเนินต่อไป ถ้ายังไม่ถึงรอบที่ 5
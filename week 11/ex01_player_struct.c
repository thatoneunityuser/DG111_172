#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char name[30];
    int hp, max_hp, attack, defense, level, gold;
} Player;
// struct ใช้ในการเก็บข้อมูลของผู้เล่น เช่น ชื่อ, พลังชีวิต, พลังโจมตี, พลังป้องกัน, ระดับ และจำนวนทอง
Player createPlayer(const char *name, int hp, int atk, int def, int level)
{
    Player p;
    strncpy(p.name, name, sizeof(p.name) - 1); //
    p.name[sizeof(p.name) - 1] = '\0';         // ป้องกัน buffer overflow
    p.hp = hp;
    p.max_hp = hp;
    p.attack = atk;
    p.defense = def;
    p.level = level;
    p.gold = 0;
    return p;
}
// ฟังก์ชันนี้สร้างผู้เล่นใหม่โดยรับค่าชื่อ, พลังชีวิต, พลังโจมตี, พลังป้องกัน และระดับของผู้เล่น จากนั้นคืนค่า struct Player ที่สร้างขึ้น
void displayPlayer(const Player *p)
{
    printf("Name: %s\n", p->name); // แสดงชื่อของผู้เล่นโดยดึงค่าจาก struct Player ที่ชี้โดย pointer p
    printf("Level: %d\n", p->level);
    printf("HP: %d/%d\n", p->hp, p->max_hp);
    printf("ATK: %d\n", p->attack);
    printf("DEF: %d\n", p->defense);
    printf("Gold: %d\n", p->gold);
}
// p.var = value; // ใช้ในการกำหนดค่าสมาชิกของ struct Player ที่ชี้โดย pointer p
//  level + 1, attack/defense +10%, max_hp + 25
void levelUp(Player *p)
{
    p->level += 1;
    p->attack = p->attack * 110 / 100;
    p->defense = p->defense * 110 / 100;
    p->max_hp += 25;
}
// returns 1 if hp > 0, otherwise 0
int isAlive(const Player *p)
{
    return p->hp > 0;
}
// reduce hp by dmg, clamped at 0
void takeDamage(Player *p, int dmg, bool parry)
{
    if (parry)
    {
        printf("%s parried the attack! No damage taken.\n", p->name);
        parry = false; // Reset parry status after successful parry
        return;
    }
    else
    {
        p->hp -= dmg;
        if (p->hp < 0)
        {
            p->hp = 0;
        }
    }
}
void ParryOrNot(int *ParryLeft, int *ParryTime, bool *parry)
{
    if (*ParryLeft > 0)
    {
        printf("You have %d parries left. Do you want to parry? (y/n): ", *ParryLeft);
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            printf("You parried the attack! You have %d seconds to counterattack.\n", *ParryTime);
            (*ParryLeft)--;
            *parry = true;
            // Implement parry logic here
        }
        else
        {
            printf("You chose not to parry.\n");
        }
    }
    else
    {
        printf("No parries left!\n");
    }
}

int main()
{
    bool parry = false;
    int parrycount = 3;
    int parrytime = 5;

    Player p = createPlayer("Dragon Knight", 100, 55, 40, 7);
    p.gold = 2350;
    takeDamage(&p, 15, false);
    displayPlayer(&p);
    printf("Alive: %s\n", isAlive(&p) ? "yes" : "no");
    printf("\n--- Level Up ---\n");
    levelUp(&p);
    displayPlayer(&p);
    printf("\n--- Take 999 damage ---\n");
    ParryOrNot(&parrycount, &parrytime, &parry);
    if (!parry)
    {
        takeDamage(&p, 999, false);
    }
    displayPlayer(&p);
    printf("Alive: %s\n", isAlive(&p) ? "yes" : "no");
    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
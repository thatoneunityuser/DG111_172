#include <stdio.h>
int main()
{
    char Character_Name[50];
    const int Max_HP;
    const int ATTACK_POWER;
    const int Defense;
    const int LEVEL;

    printf(" === Create Character ===\n");
    printf("Character Name: ");
    scanf("%s", Character_Name);
    printf("Max HP: ");
    scanf("%d", &Max_HP);
    printf("Attack Power: ");
    scanf("%d", &ATTACK_POWER);
    printf("Defense: ");
    scanf("%d", &Defense);
    printf("Level: ");
    scanf("%d", &LEVEL);
    printf("\n === Character Summary ===\n");
    printf("Name: %s\n", Character_Name);
    printf("Lvl: %d\n", LEVEL);
    printf("Max HP: %d\n", Max_HP);
    printf("Atk: %d\n", ATTACK_POWER);
    printf("Def: %d\n", Defense);

    return 0;
}
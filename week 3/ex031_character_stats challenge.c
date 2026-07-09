#include <stdio.h>
int main()
{
    char Character_Name[50];
    const int Max_HP = 1000;

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
    printf("\n === Character Sheet ===\n");
    printf("╔══════════════════════════════╗\n");
    printf("║ Name: %-22s ║\n", Character_Name);
    printf("║ Lvl: %-23d ║\n", LEVEL);
    printf("║ Max HP:%-1d/%-18d║\n", Max_HP, Max_HP);
    printf("║ Atk: %-23d ║\n", ATTACK_POWER);
    printf("║ Def: %-23d ║\n", Defense);
    printf("╠══════════════════════════════╣\n");

    printf("║ HP Bar: [██████████] 100%    ║\n");
    printf("║ Power Score = %-14d ║\n", ATTACK_POWER * 2 + Defense + Max_HP / 10);
    printf("╚══════════════════════════════╝\n");

    return 0;
}
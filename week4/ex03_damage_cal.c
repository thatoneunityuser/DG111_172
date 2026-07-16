#include <stdio.h>
#include <math.h>

int main()
{
    int Player_Attack, Enemy_Defense, Hit_Number;
    float Damage, Crit_Hit;
    printf("Enter Player Attack: ");
    scanf("%d", &Player_Attack);
    printf("Enter Enemy Defense: ");
    scanf("%d", &Enemy_Defense);
    printf("Enter Hit Number: ");
    scanf("%d", &Hit_Number);

    Damage = (Player_Attack - Enemy_Defense);
    Crit_Hit = (int)ceil((float)Damage * 1.5f);
    printf("=== COMBAT SIMULATOR ===\n");

    if (Hit_Number % 5 == 0 && Hit_Number != 0)
    {
        printf("Critical Hit! Damage: %.2f *******(CRITICAL)**********\n", Crit_Hit);
    }
    else if (Hit_Number != 0)
    {
        printf("Damage: %.2f (NORMAL)\n", Damage);
    }
    else
    {
        printf("No damage dealt. Hit number is zero.\n");
    }

    return 0;
}
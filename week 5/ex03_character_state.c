#include <stdio.h>

int main()
{
    int max_hp, damage, hit;
    int poisoned;
    int currenthp, currenthpbar;

    enum state
    {
        NORMAL,
        POISONED,
        DEAD,
        CRITICAL
    };
    enum state current_state = NORMAL;

    printf("Max HP: ");
    scanf("%d", &max_hp);
    printf("Damage Taken: ");
    scanf("%d", &damage);
    printf("POISONED (1 for yes, 0 for no): ");
    scanf("%d", &poisoned);
    printf("How many Hits: ");
    scanf("%d", &hit);

    printf("\n=== Character Status ===\n");

    currenthp = max_hp - damage;
    if (currenthp <= max_hp / 25)
    {
        current_state = CRITICAL;
    }

    else if (currenthp <= 0)
    {
        currenthp = 0;
        current_state = DEAD; // ห้าม hp ติดลบ
    }
    else
    {
        current_state = NORMAL;
    }

    if (hit > 0)
    {
        printf("You do %d hits!\n", hit);
        if (hit % 5 == 0)
        {
            printf("YOU RECIVED ULTIMATE \n");
        }
    }
    if (poisoned)
    {

        printf("You are poisoned! \n");
        current_state = POISONED;
    }

    currenthpbar = currenthp * 10 / max_hp;
    for (int i = 0; i < currenthpbar; i++)
    {
        printf("█");
    }
    for (int i = currenthpbar; i < 10; i++)
    {
        printf("░");
    }

    printf("Current HP:  %d/%d", currenthp, max_hp);
    if (current_state == CRITICAL)
    {
        printf(" CRITICAL \n");
    }
    else
    {
        printf("\n");
    }
    printf("Current State: %s\n", current_state == NORMAL ? "NORMAL" : current_state == POISONED ? "POISONED"
                                                                   : current_state == DEAD       ? "DEAD"
                                                                                                 : "CRITICAL");
    return 0;
}
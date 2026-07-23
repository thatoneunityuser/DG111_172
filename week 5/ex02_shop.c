#include <stdio.h>

int main()
{
    int gold = 1000;
    int overall_cost = 0;

    int HP_POTION_COST = 50;
    int MANA_POTION_COST = 80;
    int SWORD_COST = 500;
    int SHIELD_COST = 300;

    enum Item
    {
        HP_POTION,
        MANA_POTION,
        SWORD,
        SHIELD,
        LEAVE
    };
    enum Item Item;

    printf("--------------Welcome to the shop!--------------\n");
    printf("You have %d gold.\n", gold);
    printf("0. Leave the shop\n");
    printf("1. HP Potion - %d gold (+50 HP)\n", HP_POTION_COST);
    printf("2. Mana Potion - %d gold (+30 MP)\n", MANA_POTION_COST);
    printf("3. Sword - %d gold (+20 ATK)\n", SWORD_COST);
    printf("4. Shield - %d gold (+15 DEF)\n", SHIELD_COST);

    printf("Enter the number of the item you want to buy (1-4): ");

    int amount;
    scanf("%d \n", &Item);
    amount = Item;

    printf("You selected item number: %d%d\n", Item);

    printf("=== Purchase === \n");

    printf("All item that you bought: %d \n", amount);

    switch (Item)
    {
    case LEAVE:
        printf("Thank you for visiting the shop! You have %d gold left.\n", gold);
        break;
    case HP_POTION:
        if (gold >= HP_POTION_COST)
        {
            gold -= HP_POTION_COST;
            overall_cost += HP_POTION_COST;
            printf("You bought an HP Potion! You have %d gold left.\n", gold);
        }
        else
        {
            printf("You don't have enough gold to buy an HP Potion.\n");
        }
        break;
    case MANA_POTION:
        if (gold >= MANA_POTION_COST)
        {
            gold -= MANA_POTION_COST;
            overall_cost += MANA_POTION_COST;
            printf("You bought a Mana Potion! You have %d gold left.\n", gold);
        }
        else
        {
            printf("You don't have enough gold to buy a Mana Potion.\n");
        }
        break;
    case SWORD:
        if (gold >= SWORD_COST)
        {
            gold -= SWORD_COST;
            overall_cost += SWORD_COST;
            printf("You bought a Sword! You have %d gold left.\n", gold);
        }
        else
        {
            printf("You don't have enough gold to buy a Sword.\n");
        }
        break;
    case SHIELD:
        if (gold >= SHIELD_COST)
        {
            gold -= SHIELD_COST;
            overall_cost += SHIELD_COST;
            printf("You bought a Shield! You have %d gold left.\n", gold);
        }
        else
        {
            printf("You don't have enough gold to buy a Shield.\n");
        }
        break;

    default:
        printf("Invalid item selection.\n");
    }

    if (Item == SWORD)
    {

        printf("Attack power + 20 \n");
    }
    else if (Item == SHIELD)
    {
        printf("Defense power + 15\n");
    }
    else if (Item == HP_POTION)
    {
        printf("HP + 50\n");
    }
    else if (Item == MANA_POTION)
    {
        printf("MP + 30\n");
    }
    if (amount >= 2)
    {
        printf("WARRIOR BUNDLE , You got 10% discount! \n");
        overall_cost = overall_cost - (overall_cost * 0.1);
    }

    printf("Total cost of all items purchased: %d gold\n", overall_cost);

    return 0;
}
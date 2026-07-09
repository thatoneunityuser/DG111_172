#include <stdio.h>
int main()
{
    char Name[50];
    int Age;
    double GPA;
    char Favorite_Subject[50];

    printf(" === Enter Data===\n");
    printf("Name: ");
    scanf("%s", Name);
    printf("Age: ");
    scanf("%d ", &Age);
    printf("GPA: ");
    scanf("%lf", &GPA);
    printf("Favorite Subject: ");
    scanf("%s", Favorite_Subject);
    printf("\n === Personal Information ===\n");
    printf("┌────────────────────────────┐\n");
    printf("│ Name : %-20s│\n", Name);
    printf("│ Age : %-1d Year old           │\n", Age);
    printf("│ GPA : %-20.0f │\n", GPA);
    printf("│ Favorite Subject : %-8s│\n", Favorite_Subject);
    printf("└────────────────────────────┘\n");

    return 0;
}
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
    scanf("%d", &Age);
    printf("GPA: ");
    scanf("%lf", &GPA);
    printf("Favorite Subject: ");
    scanf("%s", Favorite_Subject);
    printf("\n === Personal Information ===\n");
    printf("Name: %s\n", Name);
    printf("Age: %d\n", Age);
    printf("GPA: %.2lf\n", GPA);
    printf("Favorite Subject: %s\n", Favorite_Subject);

    return 0;
}
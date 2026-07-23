#include <stdio.h>

int main()
{
    int grade;
    printf("Enter your grade (0-100): ");
    scanf("%d", &grade);

    if (grade >= 80 && grade <= 100)
    {
        printf("Your letter grade is: A (4.0) Pass\n");
    }
    else if (grade >= 75 && grade < 80)
    {
        printf("Your letter grade is: B+ (3.5) Pass\n");
    }
    else if (grade >= 70 && grade < 75)
    {
        printf("Your letter grade is: B (3.0) Pass\n");
    }
    else if (grade >= 65 && grade < 70)
    {
        printf("Your letter grade is: C+ (2.5) Pass\n");
    }
    else if (grade >= 60 && grade < 65)
    {
        printf("Your letter grade is: C (2.0) Pass\n");
    }
    else if (grade >= 55 && grade < 60)
    {
        printf("Your letter grade is: D+ (1.5) Pass\n");
    }
    else if (grade >= 50 && grade < 55)
    {
        printf("Your letter grade is: D (1.0) Pass\n");
    }
    else if (grade >= 0 && grade < 50)
    {
        printf("Your letter grade is: F (0.0) Fail\n");
    }
    else
    {
        printf("Invalid grade entered. Please enter a value between 0 and 100.\n");
    }

    return 0;
}
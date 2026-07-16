#include <stdio.h>
#include <math.h>

int main()
{

    float Weight, HeightM, BMI, HeightCM;
    printf("Enter your weight (kg): ");
    scanf("%f", &Weight);
    printf("Enter your height (cm): ");
    scanf("%f", &HeightCM);

    HeightM = HeightCM / 100.0;
    BMI = Weight / (HeightM * HeightM);

    printf("Your BMI is: %.2f\n", BMI);
    if (BMI < 18.5)
    {
        printf("You are underweight.\n");
    }
    else if (BMI >= 18.5 && BMI < 24.9)
    {
        printf("You have a normal weight.\n");
    }
    else if (BMI >= 25 && BMI < 29.9)
    {
        printf("You are overweight.\n");
    }
    else
    {
        printf("You are obese.\n");
    }

    return 0;
}
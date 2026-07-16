#include <stdio.h>
#include <math.h>

int main()
{

    int seconds;
    printf("Enter the number of seconds: ");
    scanf("%d", &seconds);
    int minutes = (seconds % 3600) / 60;

    int hours = seconds / 3600;

    int secs = seconds % 60;

    printf("OUTPUT : %02d : %02d : %02d\n", hours, minutes, secs);
    // Countdown loop
    while (seconds > 0)
    {
        printf("Countdown: %02d : %02d : %02d\n", hours, minutes, secs);
        secs--;

        if (secs < 0)
        {
            secs = 59;
            minutes--;
        }
        if (minutes < 0)
        {
            minutes = 59;
            hours--;
        }
        if (secs == 0 && minutes == 0 && hours == 0)
        {
            printf("Countdown: %02d : %02d : %02d\n", hours, minutes, secs);
            printf("Time's up!\n");
            break;
        }
    }

    return 0;
}
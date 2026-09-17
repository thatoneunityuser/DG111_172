#include <stdio.h>
#include <math.h>
#define MAX_N 20
void minMax(int arr[], int n, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
    }
}
int clamp(int value, int min, int max)
{
    if (value > max)
        value = max;
    if (value < min)
        value = min;
    return value;
}

int main()
{
    int n, NIGGA;
    printf("n (max %d): ", MAX_N);
    scanf("%d", &n);
    int arr[MAX_N], lo, hi;
    NIGGA = clamp(n, 0, MAX_N);
    for (int i = 0; i < NIGGA; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    minMax(arr, NIGGA, &lo, &hi);
    printf("lo=%d, hi=%d\n", lo, hi);
    return 0;
}

// * used to dereference a pointer to access the value it points to
// & used to get the address of a variable
// อันนี้  n max = 20 จริงๆละครับ

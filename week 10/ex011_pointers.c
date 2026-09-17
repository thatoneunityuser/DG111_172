#include <stdio.h>
int main()
{
    int x = 5;
    int *ptr = &x; // ptr points to the address of x
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void *)&x); // we use (void *) to avoid warnings about format specifiers
    printf("Value of ptr: %p\n", (void *)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);
    // so x = *ptr and ptr = &x, which means that *ptr is the value of x and ptr is the address of x.

    // Modify the value of x using the pointer
    *ptr = 100;
    printf("New value of x: %d\n", x);

    return 0;
}
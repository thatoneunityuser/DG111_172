#include <stdio.h>
#include <math.h>
//-------------1.1 — Integer Division & Modulo:-------------
// int main()
//{
//  printf(" %d", 10 / 3);
// printf(" %f", 10.0 / 3);
// printf(" %f", (float)10 / 3);

// int FORTEST = 10 % 3;
//  printf(" %d", FORTEST);
// int FORTEST2 = -7 % 3;
// printf(" %d", FORTEST2);
// int FORTEST3 = 7 % -3;
// printf(" %d", FORTEST3);

// return 0;
//}
//-------------1.2 — Increment & Decrement:-------------
// int main()
//{
// int x = 5;
// printf("x++ = %d\n", x++);
// printf("x = %d\n", x); // show ก่อนค่อยเพิ่มค่า
// x = 5;
// printf("++x = %d\n", ++x); // เพิ่มค่าก่อนค่อย show
// printf("x = %d\n", x);

// return 0;
//}
//-------------1.3 — Precedence Test:-------------
int main()
{
    printf("2 + 3 * 4 = %d\n", 2 + 3 * 4);
    printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);
    printf("10 - 2 - 3 = %d\n", 10 - 2 - 3);
    printf("2*3 + 4*5 = %d\n", 2 * 3 + 4 * 5);
    // multiply and divide have higher precedence than add and subtract, so they are evaluated first. The order of evaluation is from left to right, so the expression is evaluated as follows:

    return 0;
}
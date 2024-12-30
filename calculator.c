// The Euclidean algorithm is a process that, given two integers a and b ̸= 0 as inputs, efficiently finds gcd(a, b)

#include <stdio.h>

int getRemainder(int r0, int r1) {

    int mul = 0;

    while (r0 > (r1 * mul)) {
        mul++;
    }

    if (r0 != (r1 * mul)) {
        mul--;
    }
    return (r0 - r1 * mul);
}

int main(void) {

    int a, b;
    printf("Input value of a and b: ");
    scanf("%d %d", &a, &b);
    getchar();

    // printf("a: %d, b: %d\n", a, b);

    printf("Calculating......\n");

    int temp0 = a;
    int temp1 = b;
    int nowRemainder;

    while (1) {
        nowRemainder = getRemainder(temp0, temp1);
        // The process terminates immediately after the nth step, when the remainder is first found to be zero
        if(nowRemainder == 0) {
            break;
        }

        temp0 = temp1;
        temp1 = nowRemainder;
        // printf("now temp0: %d, temp1: %d\n", temp0, temp1);
    }

    printf("Finished\n");
    printf("The GCD of %d and %d is %d\n", a, b, temp1);

    return 0;
}

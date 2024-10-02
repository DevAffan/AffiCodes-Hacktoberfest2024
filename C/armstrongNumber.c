#include <stdio.h>
#include <math.h>

int isArmstrong(int number) {
    int originalNum, remainder, result = 0, n = 0;

    originalNum = number;

    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = number;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    return (result == number);
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (isArmstrong(number))
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);

    return 0;
}

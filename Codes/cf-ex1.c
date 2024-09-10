#include <stdio.h>

int main() {
    int num;
    printf("Enter a number (1-100): ");
    scanf("%d", &num);

    // if statement
    if (num > 50) printf("Greater than 50\n");

    // if-else statement
    (num % 2 == 0) ? printf("Even\n") : printf("Odd\n");

    // if-else-if statement
    if (num >= 90) printf("Grade: A\n");
    else if (num >= 80) printf("Grade: B\n");
    else if (num >= 70) printf("Grade: C\n");
    else if (num >= 60) printf("Grade: D\n");
    else printf("Grade: F\n");

    return 0;
}

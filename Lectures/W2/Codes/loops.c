#include <stdio.h>

int main() {
    int i;
    // A for loop from 1 to 10
    for (i = 1; i <= 10; i++) {
        // Check if the number is 5, skip iteration
        if (i == 5) {
            printf("Skipping number 5\n");
            continue;  // Skip the current iteration when i is 5
        }
        // If the number is 8, break the loop
        if (i == 8) {
            printf("Breaking the loop at number 8\n");
            break;  // Exit the loop when i is 8
        }
        // Print the current number if none of the conditions are met
        printf("Current number: %d\n", i);
    }
    return 0;
}


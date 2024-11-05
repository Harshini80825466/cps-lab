#include <stdio.h>

int main() {
    int numbers[10];      // Array to store 10 integers
    int *ptr = numbers;   // Pointer to the array
    int max;

    // Taking input for 10 integers
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", ptr + i);  // Use pointer arithmetic to store values
    }

    // Initialize max with the first element
    max = *ptr;  // Dereferencing the pointer to get the first value

    // Loop to find the maximum value
    for (int i = 1; i < 10; i++) {
        if (*(ptr + i) > max) {  // Compare each element with the current max
            max = *(ptr + i);     // Update max if a larger value is found
        }
    }

    // Output the maximum value
    printf("The maximum value is: %d\n", max);

    return 0;
}

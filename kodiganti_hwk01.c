#include<stdio.h>
#include<stdlib.h>
#define SIZE 30

int main()
{
    int number[SIZE]; 
    int i = 0;
    FILE* in_file = fopen("data.txt", "r"); // Open the file in read mode. 
         
    if (!in_file) {  // If the file can't be read, exit the program
        printf("oops, file can't be read\n"); 
        exit(-1); 
    }

    // Read numbers from the file
    while (fscanf(in_file, "%d", &number[i]) == 1) { 
       // printf("Scores read: %d\n", number[i]);
        i++; 
    }

    int counter_mat[SIZE][2]; // Array to store numbers and their corresponding count
    for (i = 0; i < SIZE; ++i) {
        counter_mat[i][0] = number[i];  // Store the number
        counter_mat[i][1] = 1;          // Initialize its count to 1
    }

    // Count the occurrences of each number
    for (i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {  // Compare only subsequent numbers to avoid double counting
            if (number[i] == number[j]) {
                counter_mat[i][1]++;  // Increment count for number[i]
                counter_mat[j][1] = 0;  // Mark number[j] as counted
            }
        }
    }

    // Find the maximum frequency (mode)
    int max = counter_mat[0][1];
    for (i = 1; i < SIZE; ++i) {
        if (max < counter_mat[i][1]) {
            max = counter_mat[i][1];
        }
    }

    // Flag array to track if a number has already been printed
    int printed[SIZE] = {0}; // Initialize a 'printed' array to keep track of printed mode numbers

   // printf("All numbers that are repeated atmost  %d times (multiple Mode):\n", max);
    printf("Mode are");
    // Loop through the numbers and print only the ones that have the maximum frequency
    for (i = 0; i < SIZE; ++i) {
        if (counter_mat[i][1] == max && printed[i] == 0) {
             
             // Only print if it hasn't been printed already
            printf(" %d ", counter_mat[i][0]);
           
          
            printed[i] = 1;  // Mark this number as printed
        }
    }
      printf("\n");
      printf("The Mode elements are repeated  %d times (multiple Mode)\n", max);
  
    return 0;
}



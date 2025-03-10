#include <stdio.h>    // Standard Input/Output library for printing
#include <math.h>     // Math library for calculating square roots
#include "stats.h"    // Header file declaring statistical functions and including the Student structure

/** Part 3: Overall Stats and Best Student
 *@author Dmitriy Breen

 */
void compute_overall_stats(const Student students[], int student_count, float averages[], float std_devs[]) {
    // Iterate over each assignment (grade index)
    for (int i = 0; i < MAX_GRADES; i++) {
        float sum = 0;            // Sum of grades for this assignment
        float sum_of_squares = 0; // Sum of squares of grades for this assignment

        // Loop through all students to process their grades for this assignment
        for (int j = 0; j < student_count; j++) {
            sum += students[j].grades[i];                               // Add the grade to the sum
            sum_of_squares += students[j].grades[i] * students[j].grades[i]; // Add the square of the grade
        }

        // Compute the average for this assignment
        averages[i] = sum / student_count;

        // Compute the standard deviation for this assignment
        std_devs[i] = sqrt(sum_of_squares / student_count - averages[i] * averages[i]);
    }
}

int find_best_students(const Student students[], int student_count, int best_indices[]) {
    if (student_count == 0) {
        return 0; // No students available
    }

    float max_average = -1; // Variable to store the highest average score

    // Step 1: Find the maximum average score
    for (int i = 0; i < student_count; i++) {
        if (students[i].average > max_average) {
            max_average = students[i].average; // Update the maximum average
        }
    }

    int count = 0; // Counter to track the number of best students

    // Step 2: Collect the indices of students with the maximum average
    for (int i = 0; i < student_count; i++) {
        if (students[i].average == max_average) {
            best_indices[count++] = i; // Add the index of this student to the array
        }
    }

    return count; // Return the total number of best students
}

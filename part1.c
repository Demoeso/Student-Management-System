#include <stdio.h>    // Standard Input/Output library for printf and scanf
#include <math.h>     // Math library for calculating square roots
#include "student.h"  // Custom header file that defines the Student structure and related constants

/** Part 1: Managing a Single Student
 *@author Dmitriy Breen
 */
void calculate_stats(Student *student) {
    float sum = 0;            // Sum of all grades
    float sum_of_squares = 0; // Sum of the squares of all grades

    // Iterate through all grades to compute sum and sum of squares
    for (int i = 0; i < MAX_GRADES; i++) {
        sum += student->grades[i];                               // Add current grade to sum
        sum_of_squares += student->grades[i] * student->grades[i]; // Add square of current grade
    }

    // Calculate the average
    student->average = sum / MAX_GRADES;

    // Calculate the standard deviation using the provided formula
    student->std_dev = sqrt(sum_of_squares / MAX_GRADES - student->average * student->average);
}


void input_student(Student *student) {
    // Prompt for and collect the Student ID
    printf("Enter Student ID: ");
    scanf("%s", student->student_id);

    // Prompt for and collect the first name
    printf("Enter First Name: ");
    scanf("%s", student->first_name);

    // Prompt for and collect the last name
    printf("Enter Last Name: ");
    scanf("%s", student->last_name);

    // Prompt for and collect 5 grades
    printf("Enter %d grades separated by space: ", MAX_GRADES);
    for (int i = 0; i < MAX_GRADES; i++) {
        scanf("%f", &student->grades[i]); // Read each grade into the array
    }

    // Calculate the stats for the inputted grades
    calculate_stats(student);
}


void display_one_student(const Student *student) {
    // Print the Student ID
    printf("Student ID: %s\n", student->student_id);

    // Print the last name (surname)
    printf("Student Surname: %s\n", student->last_name);

    // Print the first name
    printf("Student Name: %s\n", student->first_name);

    // Print the grades in a comma-separated format
    printf("Student Marks: ");
    for (int i = 0; i < MAX_GRADES; i++) {
        printf("%.0f", student->grades[i]); // Print the grade rounded to 0 decimals
        if (i < MAX_GRADES - 1) {
            printf(", "); // Add a comma between grades, except for the last one
        }
    }

    // Print the calculated average
    printf("\nAverage Mark: %.2f\n", student->average);

    // Print the calculated standard deviation
    printf("Standard Deviation: %.2f\n", student->std_dev);
}

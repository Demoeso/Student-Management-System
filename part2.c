#include <stdio.h>     // Standard Input/Output library for printf and scanf
#include <string.h>    // String library for strcmp
#include "management.h" // Header file declaring multi-student management functions

/** Part 2: Managing Multiple Students
 *@author Dmitriy Breen
 */
int add_student(Student students[], int *student_count, const Student *new_student) {
    // Check if the array is full
    if (*student_count >= MAX_STUDENTS) {
        return 0; // Array full, cannot add new student
    }

    // Add the new student to the array
    students[*student_count] = *new_student;

    // Increment the student count
    (*student_count)++;
    return 1; // Indicate success
}


int find_student_by_id(const Student students[], int student_count, const char *student_id) {
    // Iterate through the array of students
    for (int i = 0; i < student_count; i++) {
        // Compare the given student ID with the current student's ID
        if (strcmp(students[i].student_id, student_id) == 0) {
            return i; // Found the student, return their index
        }
    }

    // No match found, return -1
    return -1;
}


void display_all_students(const Student students[], int student_count) {
    // Check if there are no students to display
    if (student_count == 0) {
        printf("No students to display.\n");
    } else {
        // Print the header row of the table
        printf("Student ID    Name       Surname      Average    STD Deviation\n");

        // Iterate through each student and print their details
        for (int i = 0; i < student_count; i++) {
            printf("%-12s %-10s %-12s %-10.2f %.2f\n",
                   students[i].student_id,   // Student ID
                   students[i].first_name,  // First name
                   students[i].last_name,   // Last name
                   students[i].average,     // Average of grades
                   students[i].std_dev);    // Standard deviation of grades
        }
    }
}


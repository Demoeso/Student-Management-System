#include <stdio.h>     // Standard Input/Output library for printing
#include <string.h>    // String library for strcmp and strcasecmp
#include "management.h" // Header file declaring student management functions

/** Part 4: Remove and Sort Students
 *@author Dmitriy Breen
 */
int remove_student(Student students[], int *student_count, const char *student_id) {
    // Iterate through the students to find the one with the matching ID
    for (int i = 0; i < *student_count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            // Found the student; shift subsequent students to fill the gap
            for (int j = i; j < *student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            // Decrement the total number of students
            (*student_count)--;
            return 1; // Return success
        }
    }
    return 0; // Return failure if no match is found
}



void sort_students(Student students[], int student_count, int by_average) {
    Student temp_students[MAX_STUDENTS]; // Temporary copy of the array
    memcpy(temp_students, students, sizeof(Student) * student_count); // Copy the original array

    // Use a comparison-based sorting algorithm
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            int should_swap = 0;

            if (by_average) {
                // Sort by average (descending)
                should_swap = temp_students[i].average < temp_students[j].average;
            } else {
                // Sort by first name (ascending), case-insensitive
                int first_name_cmp = strcasecmp(temp_students[i].first_name, temp_students[j].first_name);
                if (first_name_cmp > 0) {
                    should_swap = 1; // First name comes later alphabetically
                } else if (first_name_cmp == 0) {
                    // If first names are the same, sort by last name
                    if (strcasecmp(temp_students[i].last_name, temp_students[j].last_name) > 0) {
                        should_swap = 1;
                    }
                }
            }

            // Swap the students if needed
            if (should_swap) {
                Student temp = temp_students[i];
                temp_students[i] = temp_students[j];
                temp_students[j] = temp;
            }
        }
    }

    // Display the sorted students (does not modify the original array)
    display_all_students(temp_students, student_count);
}

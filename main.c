#include <stdio.h>       // Standard Input/Output library for printf and scanf
#include "student.h"     // Header file defining Student structure and related functions
#include "management.h"  // Header file for multi-student management functions
#include "stats.h"       // Header file for statistical functions

/** Part 5: Main Menu and Program Logic
 *@author Dmitriy Breen

 */
void show_menu() {
    printf("\n============================\n");
    printf(" Student Management System\n");
    printf("============================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Display One Student\n");
    printf("4. Show Overall Score Stats\n");
    printf("5. Find Best Student\n");
    printf("6. Remove a Student\n");
    printf("7. Sort Students\n");
    printf("8. Exit\n");
    printf("============================\n");
    printf("Enter your choice: ");
}


int main() {
    Student students[MAX_STUDENTS]; // Array to store all student data
    int student_count = 0;         // Tracks the current number of students
    int choice;                    // User's menu choice

    // Main program loop
    do {
        show_menu();               // Display the menu
        scanf("%d", &choice);      // Get the user's choice

        switch (choice) {
            case 1: { // Add a new student
                Student new_student;
                input_student(&new_student); // Input student details
                if (add_student(students, &student_count, &new_student)) {
                    printf("Student added successfully.\n");
                } else {
                    printf("Error: Maximum number of students reached.\n");
                }
                break;
            }
            case 2: // Display all students
                display_all_students(students, student_count);
                break;
            case 3: { // Display a single student
                char student_id[10];
                printf("Enter Student ID: ");
                scanf("%s", student_id);
                int index = find_student_by_id(students, student_count, student_id);
                if (index != -1) {
                    display_one_student(&students[index]); // Display the student's details
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 4: { // Show overall statistics for assignments
                float averages[MAX_GRADES], std_devs[MAX_GRADES];
                compute_overall_stats(students, student_count, averages, std_devs);
                printf("Assignment\tAverage\tStd Dev\n");
                for (int i = 0; i < MAX_GRADES; i++) {
                    printf("%d\t\t%.2f\t%.2f\n", i + 1, averages[i], std_devs[i]);
                }
                break;
            }
            case 5: { // Find and display the best student(s)
                int best_indices[MAX_STUDENTS];
                int num_best_students = find_best_students(students, student_count, best_indices);

                if (num_best_students == 0) {
                    printf("No students available.\n");
                } else {
                    printf("Best Students:\n");
                    for (int i = 0; i < num_best_students; i++) {
                        display_one_student(&students[best_indices[i]]);
                    }
                }
                break;
            }
            case 6: { // Remove a student by ID
                char student_id[10];
                printf("Enter Student ID to remove: ");
                scanf("%s", student_id);
                if (remove_student(students, &student_count, student_id)) {
                    printf("Student removed successfully.\n");
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 7: { // Sort students
                int sort_choice;
                printf("Sort by: 1. Average (descending) 2. Name (ascending): ");
                scanf("%d", &sort_choice);
                sort_students(students, student_count, sort_choice == 1);
                break;
            }
            case 8: // Exit
                printf("Exiting program.\n");
                break;
            default: // Invalid input
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8); // Exit the loop when choice is 8

    return 0; // Program termination
}

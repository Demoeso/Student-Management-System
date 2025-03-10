/**
 *@author Dmitriy Breen
 */

#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "student.h" // Includes the Student structure and constants

/* Function prototypes for managing multiple students */
int add_student(Student students[], int *student_count, const Student *new_student);
int find_student_by_id(const Student students[], int student_count, const char *student_id);
void display_all_students(const Student students[], int student_count);

#endif

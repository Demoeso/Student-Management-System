/**
 *@author Dmitriy Breen
 */

#ifndef STUDENT_H
#define STUDENT_H

/* Constants */
#define MAX_STUDENTS 10   /* Maximum number of students allowed */
#define MAX_GRADES 5      /* Number of grades per student */
#define NAME_SIZE 50      /* Maximum size for a name */

/* Structure to represent a single student */
typedef struct {
    char student_id[10];             /* Student's unique ID */
    char first_name[NAME_SIZE];      /* Student's first name */
    char last_name[NAME_SIZE];       /* Student's last name */
    float grades[MAX_GRADES];        /* Array of 5 grades */
    float average;                   /* Calculated average of grades */
    float std_dev;                   /* Calculated standard deviation of grades */
} Student;

/* Functions for managing a single student */
void input_student(Student *student);     /* Collect input for a single student */
void calculate_stats(Student *student);   /* Calculate average and standard deviation for a student */
void display_one_student(const Student *student); /* Display details of a single student */

#endif

/**
 *@author Dmitriy Breen
 */


#ifndef STATS_H
#define STATS_H

#include "student.h" // Includes the Student structure and constants

/* Function prototypes for calculating statistics and finding the best student */
void compute_overall_stats(const Student students[], int student_count, float averages[], float std_devs[]);
int find_best_student(const Student students[], int student_count);

#endif

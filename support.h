/* DO NOT MODIFY THIS FILE | NE MODIFIEZ PAS CE FICHIER */

#ifndef SUPPORT_H_
#define SUPPORT_H_

#include "student.h"
#define CONSOLE_WIDTH 240

/*
 * Support functions for question 1.
 */
void display_color(unsigned char color[3], enum StdCol col);


/*
 * Support functions for question 2.
 */
struct Action *create_original();
struct Action *create_Action();
void print_column_headings();
void last_4_of_ptr(void *p, char *buff);
void print_action(struct Action *item);
void print_original(struct Action *original) ;
void print_list(struct Action *head, struct Action *current);

/*
 * Support functions for question 3.
 */
void show_histogram(unsigned int *values, unsigned int range);

#endif /* SUPPORT_H_ */

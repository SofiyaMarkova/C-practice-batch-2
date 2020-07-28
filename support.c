/*
 ********************************************************
 * DO NOT MODIFY THIS FILE | NE MODIFIEZ PAS CE FICHIER *
 ********************************************************
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "support.h"

// Q1

/*
 * This function displays a colour in a true colour space and its equivalent in the 8-colour
 * space.
 *
 */
//pass the color from array it is on. pass the word for the color it was found to be
void display_color(unsigned char color[3], enum StdCol col) {
	unsigned char red, green, blue;//made int for same unsigned char because color[] stores unsigned char (so type corresponds)
	char color_str[8][10] = { "Black", "Red", "Green", "Blue", "Magenta", "Yellow",
			"Purple", "White" };
	red = color[0]; //save from the color[] as corresponding number for the type of color that is there. color[0] = how much red
	green = color[1]; //save from the color[] as corresponding number for the type of color that is there. color[1] = how much green
	blue = color[2]; //save from the color[] as corresponding number for the type of color that is there. color[2] = how much blue
	printf("[%d, %d, %d] is %s\n", red, green, blue, color_str[col]); //just prints them accordingly
}

// Q2

/*
 * This function creates the node representing the original.
 *
 * Return: the original node
 *
 */
struct Action *create_original() {
	struct Action *original = (struct Action *) malloc(sizeof(struct Action));
	original->id = 0;
	original->type = 0;
	original->next = NULL;
	original->prev = NULL;
	return original;
}

/*
 * This function simulates an action that could be done by the user.
 *
 * Return: a new action item
 *
 */
struct Action *create_Action() {
	static bool initialized = false;
	static unsigned int count = 1;
	if (!initialized) {
		initialized = true;
		srand(time(0));
	}

	struct Action *new = (struct Action *) malloc(sizeof(struct Action));
	new->id = count++;
	new->type = rand() % 3;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

/*
 * Prints the header of the list of nodes.
 *
 *
 */
void print_column_headings() {
	printf("%-4s  %-4s  %-4s  %-4s  %-12s\n", "ID", "Addr", "Prev", "Next",
			"Category");
	printf("----  ----  ----  ----  ------------\n");
}

/*
 * Generates a string from an address.
 *
 * p: the pointer
 * buff: the string 
 *
 */
void last_4_of_ptr(void *p, char *buff) {
	char local_buffer[20];
	sprintf(local_buffer, "%p", p);
	strncpy(buff, local_buffer + strlen(local_buffer) - 4, 4);
	buff[4] = '\0';
}

/*
 * Displays one node.
 *
 *
 * node: the node to be displayed.
 *
 */
void print_action(struct Action *node) {
	const char *category_names[3] = { "adding", "deleting", "appending" };
	const char *format = "%4d  %4s  %4s  %4s  %-12s";
	char next[5], prev[5], addr[5];
	last_4_of_ptr(node, addr);
	last_4_of_ptr(node->next, next);
	last_4_of_ptr(node->prev, prev);
	printf(format, node->id, addr, prev, next, category_names[node->type]);
}

/*
 * Displays the original node.
 *
 * anchor: the original node
 *
 */
void print_original(struct Action *original) {
	const char *format = "%4d  %4s  %4s  %4s  %-12s";
	char next[5], prev[5], addr[5];
	last_4_of_ptr(original, addr);
	last_4_of_ptr(original->next, next);
	last_4_of_ptr(original->prev, prev);
	printf(format, original->id, addr, prev, next, "original");
}

/*
 * Displays the whole list of actions.
 *
 * head: a pointer to the anchor node 
 * current: a pointer to the current action
 *
 */
void print_list(struct Action *head, struct Action *current) {
	struct Action *p_temp = head;
	print_original(p_temp);
	if (p_temp == current) {
		printf("<-- current");
	}
	printf("\n");
	p_temp = p_temp->next;
	while (p_temp != NULL) {
		print_action(p_temp);
		if (p_temp == current) {
			printf("<-- current");
		}
		printf("\n");
		p_temp = p_temp->next;
	}
}

// Q3

/*
 * Displays the histogram.
 *
 * values: an array of the histogram values
 * range: the maximum value covered by the histogram 
 *
 */
void show_histogram(unsigned int *values, unsigned int range) {
	if(values == NULL){
		printf("Empty histogram\n");
		return;
	}
	for (int i = 0; i <= range; i++) {
		if (values[i] != 0) {
			printf("%3d: %-4d | ", i, values[i]);
			for (int j = 0; j < values[i]; j++) {
				if (j > CONSOLE_WIDTH) {
					printf(">");
					break;
				}
				printf("*");
			}
			printf("\n");
		}
	}

}

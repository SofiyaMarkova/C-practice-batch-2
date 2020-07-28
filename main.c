#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "sphere.h"
#include "student.h"
#include "support.h"

// Base for tests
void test_q1(); //Q1
void test_q2(); //Q2
void test_q3(); //Q3
void test_q4(); //Q4


int main() {

//	test_q1();
//	test_q2();
test_q3();
//	test_q4();

	return EXIT_SUCCESS;
}

//Q1
//what asking: will be given a postion in cube. and relative to what color it is in the span for, that color should be printed out.
//process involves setting what color it is for what range. from there can loop and print the color for each one that is given to check
void test_q1() {
    //11 by 3 array called colors of unsigned char type (0-255 when signifide in terms of numbers for the char representation)
    //array of made up ones to check, so those need to be converted to actual color it corresponds to
	unsigned char colors[11][3] = { { 0, 0, 0 }, { 255, 255, 255 },
			{ 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 }, { 255, 255, 0 }, { 255,
					0, 255 }, { 0, 255, 255 }, { 100, 0, 0 }, { 200, 100, 0 }, {
					200, 200, 200 } };

	enum StdCol col; //declare enum as type StdCol as have. name that enum StdCol called col. declare the enum to be used
	//it fully declared in student.h

	//displays all the colors in the array as traverse and save the color turns out. sending it to display_color does the displaying
	//this is just the actual testing for putting on all the created colors/
	for (int i = 0; i < 11; i++) {
		col = convert_col(colors[i]); //call convert_col while passing the array element. the return of the function gets saved into col (returns the actual color corresponding) to be used in next function
		display_color(colors[i], col);//call display_color once find out what the enum corresponding color it is that was returned
	}
}

// Q2
void test_q2() {
	struct Action *history = NULL; //declared 2 pointers to a struct of type Action. made both to point to NULL at the start
	struct Action *current = NULL;
	history = create_original(); //save return from create_original() into history [history actually never gets used]
	current = history; //then save the history into current to be used
//traverse through array to add on 5 elements. it malloc and then connect them to make the linked list with the nodes

//(following here was already given)
	for (int i = 0; i < 5; i++) {
		current = add_node(create_Action(), current);
	}
	print_column_headings();
	print_list(history, current);

	// We undo an action
	current = undo(current);
	printf("\n\nUndo action\n");
	print_column_headings();
	print_list(history, current);

	// We redo an action
	current = redo(current);
	printf("\n\nRedo action\n");
	print_column_headings();
	print_list(history, current);

	// We do a new action
	printf("\n\nWe do a new action\n");
	current = add_node(create_Action(), current);
	print_column_headings();
	print_list(history, current);
	current = undo(current);

	// We undo an action
	printf("\n\nUndo action\n");
	print_column_headings();
	print_list(history, current);
	current = undo(current);

	// We undo an action
	printf("\n\nUndo action\n");
	print_column_headings();
	print_list(history, current);

	// We do a new action
	printf("\n\nWe do a new action\n");
	current = add_node(create_Action(), current);
	print_column_headings();
	print_list(history, current);
}

// Q3
void test_q3() {
    unsigned int *histogram = generate_histogram(img, 255); //declaring a pointer called histogram, that can point to an unsigned int
    //to that pointer set the answer of the function generate_histogram
    if(histogram == NULL){ //if pointing to NULL then say that we have empty histogram
        printf("Empty histogram\n");
        return;
    }
	show_histogram(histogram, 255); //call function to show the made histgram
}

//Q4
void test_q4() {
	char *input = "lorem.txt";
	char *output = "modified.txt";
	char *final = "final.txt";

	find_replace_str(",  ", ", ", input, output);
	find_replace_str(".  ", ". ", output, final);

}


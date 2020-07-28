#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "student.h"
#include <time.h>
#include<conio.h>

/*
 * Function to implement for question 1.
 *
 */
//recieves the small array that is part of the larger array colors. like a part of it (and that part happens to be a smaller array)
enum StdCol convert_col(unsigned char color[3]) {
	// yours | a vous

	//based on a pattern found to get the corresponding color it creates
    if (color[0]<128) //first element check = "red" (x)
        if(color[1]<128) //second element check = "green" (y)
            if(color[2]< 128) //first element check = "blue" (z)
                return BLACK;
            else
                return BLUE;
        else if (color[2]< 128)
            return GREEN;
        else
            return MAGENTA;
    else
    if(color[1]<128)
        if (color[2]<128)
            return RED;
        else
            return CYAN;
    else
    if (color[2]<128)
        return YELLOW;
    else
        return WHITE;
}

/*
 * Function to implement for question 2.
 *
 */
struct Action *add_node(struct Action *new, struct Action *current) {
	struct Action *temp = NULL;
	if (current != NULL) {
		temp = current->next;
		current->next = new;
		new->prev = current;
	}
	if (temp != NULL) {
		delete_following_action(temp);
	}
	return new;
}

/*
 * Function to implement for question 2.
 *
 */
void delete_following_action(struct Action *entry_point) {
// yours | a vous
    entry_point = NULL; //after the deletion, here need to set the pointer entry_point to NULL (so no point anywhere and ready to be deleted)
    free(entry_point); //now free the pointer that was pointing to NULL
}

/*
 * Function to implement for question 2.
 *
 */
struct Action *undo(struct Action *current) {
	// yours | a vous
    struct Action *temp = NULL; //
    if (current != NULL) {
        temp = current->prev;
        current = temp;
    }
    if (temp != NULL) {
       delete_following_action(temp);
    }
	return current;
}

/*
 * Function to implement for question 2.
 *
 */
struct Action *redo(struct Action *current) {
	// yours | a vous
    struct Action *temp = NULL; //made a pointer that can point to the nodes used (which are of type struct Action).
        temp = current->next; //make temp pointer point to what the current's next is (which is the one that is meant to go back. on the doubly linked)
        current = temp; //then current goes to where temp is (so current goes back a node)
        delete_following_action(temp); //send to get deleted the temp pointer (because already served purpose of moving)
	return current;
}

/*
 * Function to implement for question 3.
 *
 */
//pass the sphere image that was generated
unsigned int *generate_histogram(unsigned char image[IMG_SIZE][IMG_SIZE],
		unsigned char range) {
    unsigned int *histogram=NULL; //make pointer
    //!will not work with malloc, so using calloc
    histogram = (unsigned int *) calloc (range,sizeof(unsigned int)); //calloc from the pointer. using pointer because then set apart to make a matrix
    //with malloc would have been a big one allocated, but wanted to keep it seperated for the matrix
    // yours | a vous
    //traversing the whole sphere array
        for (int i = 0; i < IMG_SIZE; i++ ) {
            for (int j = 0; j < IMG_SIZE; j++ ) {
                histogram[image[i][j]] = histogram[image[i][j]] + 1; //to count how many times each numeber is showing up
                //because when find the one that is the same corresponding to it, then do an addition to that to show that one more of that type found
            }
        }
return histogram;
}

/*
 * Function to implement for question 4.
 *
 */
void find_replace_str(char *str, char *replace, char *in, char *out) {
	// yours | a vous
     printf("str '%s' replace '%s' in %s out %s \n", str, replace, in, out);


}


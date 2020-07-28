/*
 ********************************************************
 * DO NOT MODIFY THIS FILE | NE MODIFIEZ PAS CE FICHIER *
 ********************************************************
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#define COLOR_THRES 122.5
#define IMG_SIZE 42

/*
 * Colour range for question 1.
 */
enum StdCol {
	BLACK, RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, WHITE
};

/*
 * Definitions needed for question 2
 */
typedef enum {
	ADD = 1, DELETE, APPEND
} ActionType;

struct Action {
	unsigned int id;
	ActionType type;
	struct Action *prev;
	struct Action *next;
};


/*
 * Function declaration for question 1
 */
enum StdCol convert_col(unsigned char color[3]);

/*
 * Function declaration for question 2
 */
struct Action *add_node(struct Action *new, struct Action *current);
struct Action *undo(struct Action *current);
struct Action *redo(struct Action *current);
void delete_following_action(struct Action *entry_point);

/*
 * Function declaration for question 3
 */
unsigned int *generate_histogram(unsigned char img[IMG_SIZE][IMG_SIZE],
		unsigned char range);

/*
 * Function declaration for question 4
 */
void find_replace_str(char *str, char *replace, char *in, char *out);

#endif /* STUDENT_H_ */

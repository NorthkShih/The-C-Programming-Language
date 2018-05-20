/*
 * The C programming Language, Brian W. Kernighan and Dennis M. Ritchie
 * Second Edition
 * Exercise 1-16
 * Print the length of the longest line when having arbitrarily long input lines.
 */


#include <stdio.h>

#define MAX_STRING_LENGTH 5 //set a small size for ease of test

int get_line(char *line, int max_length)
{
	if (max_length < 2) {
		printf("get_line error: max_length cannot be less than 2\n");
		return 0;
	}

	int i;
	for (i = 0; i < max_length - 1; i++) {
		line[i] = getchar();
		if (line[i] == EOF) {
			return i;
		}
		if (line[i] == '\n') {
			line[i + 1] = '\0';
			return i + 1;
		}
	}

	line[i] = '\0';
	return i;
}

int main()
{
	int max_line_length = 0;
	int line_length, return_length;
	char line[MAX_STRING_LENGTH] = {0};
	int stop_loop = 0;

	// Go through each line
	while (stop_loop == 0 && (line_length = return_length = get_line(line, MAX_STRING_LENGTH)) != 0) {
		// Check if end of line
		while (return_length == MAX_STRING_LENGTH - 1
			&& line[return_length - 1] != '\n') {
			printf("%s", line);
			return_length = get_line(line, MAX_STRING_LENGTH);
			line_length += return_length;
		}
		//replace the '\n' to ' ' in the original line
		if (line[return_length - 1] == '\n')
			line[return_length - 1] = ' ';
		//catch the EOF input at the end of line
		if (line[return_length] == EOF) {
			line[return_length] = '\0';
			stop_loop = 1;
		}
		printf("%s:%d\n", line, line_length);

		// Update max length
		if (line_length > max_line_length)
			max_line_length = line_length;
	}

	// Print the max length
	printf("Max line length: %d\n", max_line_length);

	return 0;
}

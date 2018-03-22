/*
 * The C programming Language, Brian W. Kernighan and Dennis M. Ritchie
 * Second Edition
 * Exercise 1-13
 * Print a histogram (horizontal and vertical) of the lengths of words in its input.
 */


#include <stdio.h>

#define IN 1	// inside a word
#define OUT 0	// ouside a word
#define MAX_LENGTH 10	// the max length being recorded

static inline void update_word_length_record(int *wl_record, int wl)
{
	if (wl == 0)
		return;

	if (wl > MAX_LENGTH) {
		//update out of range
		wl_record[0]++;
	} else {
		wl_record[wl]++;
	}
}

int main()
{
	int c;
	int wl = 0;
	int wl_record[MAX_LENGTH+1] = {0};

	//get each character, count the word length, and record the word length
	while ((c=getchar()) != '\n') {
		if (c==' ' || c=='\t') {
			update_word_length_record(wl_record, wl);
			wl = 0;
		} else {
			wl++;
		}
	}
	update_word_length_record(wl_record, wl);

	//print word length record
	//TODO: write print record as a function
	printf("\n[Print word length record]\n");
	int temp;
	for (int i = 1; i <= MAX_LENGTH; i++) {
		printf("%7d\t",i);
		temp = wl_record[i];
		while(temp != 0) {
			printf("*");
			temp--;
		}
		printf("%3d \n", wl_record[i]);
	}
	printf(" others\t");
	temp = wl_record[0];
	while (temp != 0) {
		printf("*");
		temp--;
	}
	printf("%3d \n", wl_record[0]);

	//TODO: print record vertically

	return 0;
}

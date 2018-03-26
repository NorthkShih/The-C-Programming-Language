/*
 * The C programming Language, Brian W. Kernighan and Dennis M. Ritchie
 * Second Edition
 * Exercise 1-13
 * Print a histogram (horizontal and vertical) of the lengths of words in its input.
 */


#include <stdio.h>

#define MAX_LENGTH 10	// the max length being recorded

static inline void update_word_length_record(int *wl_record, int wl)
{
	if (wl == 0)
		return;
	if (wl > MAX_LENGTH)
		wl_record[0]++; //update out of range
	else
		wl_record[wl]++;
}

void print_record(int* wl_record)
{
	printf("\n[Print word length record]\n");
	for (int i = 1; i <= MAX_LENGTH; i++) {
		printf("%7d\t", i);
		for (int j = 0; j < wl_record[i]; j++)
			printf("*");
		printf("%3d \n", wl_record[i]);
	}
	printf(" others\t");
	for (int j = 0; j < wl_record[0]; j++)
		printf("*");
	printf("%3d \n", wl_record[0]);
}

void print_record_vertical(int* wl_record)
{
	printf("\n[Print word length record vertically]\n");
	for (int i = 1; i<= MAX_LENGTH; i++)
		printf("%7d ", i);
	printf(" others\n");
	for (int i = 0; i<= MAX_LENGTH; i++)
		printf("--------");
	printf("\n");
	
	int n_finish = 0; //number of finished wl_record
	int count = 0; //current printing count
	while( n_finish != MAX_LENGTH + 1) {
		for (int i = 1; i <= MAX_LENGTH; i++) {
			if (wl_record[i] > count)
				printf("      * ");
			else if (wl_record[i] == count)
				printf("%7d ", count);
			else { 
				if(wl_record[i] == count - 1)
					n_finish++;
				printf("        ");
			}
		}
		if (wl_record[0] > count)
			printf("      * ");
		else if (wl_record[0] == count)
			printf("%7d ", count);
		else if (wl_record[0] == count - 1)
			n_finish++;
		printf("\n");
		count++;
	}
}

void print_record_vertical_up(int* wl_record)
{
	printf("\n[Print word length record vertically (UP)]\n");
	int max_wl_record = 0;
	for (int i = 0; i<= MAX_LENGTH; i++) {
		if (max_wl_record < wl_record[i])
			max_wl_record = wl_record[i];
	}
	
	int count = max_wl_record; //current printing count
	while( count >= 0) {
		for (int i = 1; i <= MAX_LENGTH; i++) {
			if (wl_record[i] > count)
				printf("      * ");
			else if (wl_record[i] == count)
				printf("%7d ", count);
			else
				printf("        ");
		}
		if (wl_record[0] > count)
			printf("      * ");
		else if (wl_record[0] == count)
			printf("%7d ", count);
		printf("\n");
		count--;
	}

	for (int i = 0; i<= MAX_LENGTH; i++)
		printf("--------");
	printf("\n");
	for (int i = 1; i<= MAX_LENGTH; i++)
		printf("%7d ", i);
	printf(" others\n");
}

int main()
{
	int c;
	int wl = 0; //word length
	int wl_record[MAX_LENGTH+1] = {0}; //wl_record[0] represents "others"

	//get each character, count the word length, and record the word length
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			update_word_length_record(wl_record, wl);
			wl = 0;
		} else
			wl++;
	}
	update_word_length_record(wl_record, wl);

	//print word length record
	print_record(wl_record);
	//print record vertically
	print_record_vertical(wl_record);
	print_record_vertical_up(wl_record);

	return 0;
}

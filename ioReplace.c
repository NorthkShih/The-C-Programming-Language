/*
 * The C programming Language, Brian W. Kernighan and Dennis M. Ritchie
 * Second Edition
 * Exercise 1-10
 * Copy input to output, replacing each tab by \t, backslash by \\
 */

#include <stdio.h>

int main()
{
	int c;
	while ((c = getchar()) != '\n') {
		if(c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}
	putchar(c); // put '\n'

	return 0;
}

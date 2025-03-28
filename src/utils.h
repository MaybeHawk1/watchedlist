#ifndef __UTILS_H
#define __UTILS_H

#include <stdbool.h>

/*
*   Panic and exit the program
*   @param {string} s error message
*   @returns None
*/
void panic(const char *s);

/*
* Print the usage
* @param None
* @returns None
*/
void usage(void);

/*
*   Remove the newline from a string
*   @param {string} s the string
*/
void remove_newline(char *s);

#endif // __UTILS_H

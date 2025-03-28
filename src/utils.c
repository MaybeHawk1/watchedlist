#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void panic(const char *s) {
    perror(s);
    exit(1);
}

void usage(void) {
    printf("usage: watchedlist [--add] [--remove]\n");
}

void remove_newline(char *s) {
    if (s == NULL) {
        printf("str was null");
    }
    
    char *newline_pos = strchr(s, '\n');
    if (newline_pos != NULL) {
        *newline_pos = '\0';
    }
}

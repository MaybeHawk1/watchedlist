#include "database.h"
#include "utils.h"

#if defined(WIN32) && !defined(UNIX)
    #include "sqlite3/sqlite3.h"
#else
    #include <sqlite3.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FGETS           4096
#define MAX_STATIC_STRING   8192

int main(int argc, char *argv[]) {
    sqlite3 *db;

    sqlite3_open("database.db", &db);
    if (db == NULL)
        panic("db was null");
    
    create_table(db);

    char *movie_name = malloc(100 * sizeof(char));
    int movie_year = 0;
    
    // Check if movie name was null before doing anything
    if (movie_name == NULL) {
        printf("malloc failed on string movie_name");
        return 1;
    }

    if (argc < 2) {
        usage();
        return 0;
    }

    if (strcmp("--add", argv[1]) == 0 || strcmp("-a", argv[1]) == 0) {

        // Using the third argument as the movie name
        movie_name = argv[2];
        // Using the fourth argument as the movie year
        movie_year = atoi(argv[3]); // char** to int type conversion

        movie_name = movie_name + '\0';

        add_movie(movie_name, movie_year);
    } else if (strcmp("--remove", argv[1]) == 0 || strcmp("-r", argv[1]) == 0) {
        // Using the third argument as the movie name
        movie_name = argv[2];
        // movie_name = movie_name + '\0';
        // Debug stuff again do not uncomment unless debugging
        printf("name:%s\n", movie_name);
        remove_movie(movie_name);

    } else if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
	    usage();
    }  
    
    free(movie_name);
    return 0;
}

#ifndef _DATABASE_H
#define _DATABASE_H

#if defined(WIN32) && !defined(UNIX)
    #include "sqlite3/sqlite3.h"
#else
    #include <sqlite3.h>
#endif

#define MOVIE_NOT_NULL(str) {\
    if (str == NULL)\
        panic("movie was null");\
}

/*
*   Create a table in the db provided
*   @param {sqlite3*} db database
*   @returns {int} 0 if successful, 1 if unsuccessfull
*/
int create_table(sqlite3 *db);

/*
*   Add a movie to the database
*   @param {string} movie_name name of the movie
*   @param {sqlite3*} db database file
*   @returns {int} 0 if successful, 1 if unsuccessfull
*/
int add_movie(char *movie_name, int movie_year);

/*
*   Remove a movie from the database
*   @param {string} movie_name name of the movie, to be deleted
*   @param {sqlite3*} db database
*   @returns {int} 0 if successful, 1 if unsuccessfull
*/
int remove_movie(const char *movie_name);

/*
*   View all movies
*   @param {sqlite3*} db database
*   @returns None
*/
void view_movies(sqlite3 *db);

#endif //_DATABASE_H

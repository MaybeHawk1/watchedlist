#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "utils.h"
#include "macros.h"

int create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Movies ("
                      "Title TEXT NOT NULL,"
                      "Year INTEGER NOT NULL"
                      ");";
    char *err_msg = 0;

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "sqlite error [%s]", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }

    return 0;
}

int add_movie(char *movie_name, int movie_year) {
    sqlite3 *db;
    int rc = sqlite3_open("database.db", &db);

    char sql[MAX_STATIC_STRING] = {0};
    char *err_msg = 0;
    // Check if any movie name was passed before doing anything
    MOVIE_NOT_NULL(movie_name);
    
    remove_newline(movie_name);

    snprintf(sql, MAX_SNPRINTF, "INSERT INTO Movies (Title, Year) VALUES ('%s', %d);", movie_name, movie_year);
    // Debugging stuff only uncomment when debugging
    // printf("%.s\n%d", movie_name, movie_year);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "sqlite error [%s\n]", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
   
    sqlite3_close(db);
    return 0;
}

int remove_movie(const char *movie_name) {
    sqlite3 *db;
    int rc = sqlite3_open("database.db", &db);

    char sql[MAX_STATIC_STRING] = {0};
    char *err_msg = 0;
    // Check if any movie name was passed before doing anything
    MOVIE_NOT_NULL(movie_name);

    snprintf(sql, sizeof(sql), "DELETE FROM Movies WHERE Title='%s'", movie_name);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "sqlite error [%s]", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }

    return 0;
}

//
// Created by spouk on 27.06.18.
//
#include <stdio.h>
#include <sqlite3.h>

int opendbs(char *dbsname, sqlite3 *handler);

int main() {
    char *dbsname = "simple.sqlite";
    sqlite3 *db;
    sqlite3_stmt *res;

    int result = opendbs(dbsname, db);
    if (!result) {
        fprintf(stderr, "error open/create database `%s`", dbsname);
        sqlite3_close(db);
        return 1;
    }
    

    printf("Sqlite3 current version %s\n", sqlite3_libversion());
    return 0;
}

int opendbs(char *dbsname, sqlite3 *handler) {
    int rc = sqlite3_open(dbsname, &handler);
    if (rc != SQLITE_OK) {
        return -1;
    }
    return 0;
}
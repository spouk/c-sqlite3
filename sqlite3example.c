//
// Created by spouk on 27.06.18.
//
#include <stdio.h>
#include <sqlite3.h>

int opendbs(char *dbsname, sqlite3 *handler);
void catcherErrorSqlite3(int errorSqlite);

int main() {
    char *dbsname = "simple.sqlite";
    sqlite3 *db;
    sqlite3_stmt *res;

    int result = opendbs(dbsname, db);
    catcherErrorSqlite3(result);
    if (result) {
        fprintf(stderr, "error open/create database `%s`", dbsname);
        sqlite3_close(db);
        return 1;
    }

    int rc = sqlite3_step(res);
    if (rc == SQLITE_ROW) {
        printf("%s\n", sqlite3_column_text(res, 0));
    }
    sqlite3_finalize(res);
    sqlite3_close(db);

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

void catcherErrorSqlite3(int errorSqlite) {
    switch (errorSqlite) {
        case SQLITE_OK:
            fprintf(stderr, "%s", "Successful result");
            break;
        case SQLITE_ERROR:
            fprintf(stderr, "%s", "Generic error");
            break;
        case SQLITE_INTERNAL:
            fprintf(stderr, "%s", "Internal logic error in SQLite");
            break;
        case SQLITE_PERM:
            fprintf(stderr, "%s", "Access permission denied");
            break;
        case SQLITE_ABORT:
            fprintf(stderr, "%s", "Callback routine requested an abort");
            break;
        case SQLITE_BUSY:
            fprintf(stderr, "%s", "The database file is locked");
            break;
        case SQLITE_LOCKED:
            fprintf(stderr, "%s", "A table in the database is locked");
            break;
        case SQLITE_NOMEM:
            fprintf(stderr, "%s", "A malloc() failed");
            break;
    }
}


//#define SQLITE_READONLY     8   /* Attempt to write a readonly database */
//#define SQLITE_INTERRUPT    9   /* Operation terminated by sqlite3_interrupt()*/
//#define SQLITE_IOERR       10   /* Some kind of disk I/O error occurred */
//#define SQLITE_CORRUPT     11   /* The database disk image is malformed */
//#define SQLITE_NOTFOUND    12   /* Unknown opcode in sqlite3_file_control() */
//#define SQLITE_FULL        13   /* Insertion failed because database is full */
//#define SQLITE_CANTOPEN    14   /* Unable to open the database file */
//#define SQLITE_PROTOCOL    15   /* Database lock protocol error */
//#define SQLITE_EMPTY       16   /* Internal use only */
//#define SQLITE_SCHEMA      17   /* The database schema changed */
//#define SQLITE_TOOBIG      18   /* String or BLOB exceeds size limit */
//#define SQLITE_CONSTRAINT  19   /* Abort due to constraint violation */
//#define SQLITE_MISMATCH    20   /* Data type mismatch */
//#define SQLITE_MISUSE      21   /* Library used incorrectly */
//#define SQLITE_NOLFS       22   /* Uses OS features not supported on host */
//#define SQLITE_AUTH        23   /* Authorization denied */
//#define SQLITE_FORMAT      24   /* Not used */
//#define SQLITE_RANGE       25   /* 2nd parameter to sqlite3_bind out of range */
//#define SQLITE_NOTADB      26   /* File opened that is not a database file */
//#define SQLITE_NOTICE      27   /* Notifications from sqlite3_log() */
//#define SQLITE_WARNING     28   /* Warnings from sqlite3_log() */
//#define SQLITE_ROW         100  /* sqlite3_step() has another row ready */
//#define SQLITE_DONE        101  /* sqlite3_step() has finished executing */


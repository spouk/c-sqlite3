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
        case SQLITE_READONLY:     /* Attempt to write a readonly database */
            fprintf(stderr, "%s", " Attempt to write a readonly database ");
            break;
        case SQLITE_INTERRUPT :      /* Operation terminated by sqlite3_interrupt()*/
            fprintf(stderr, "%s", " Operation terminated by sqlite3_interrupt()");
            break;
        case SQLITE_IOERR      :   /* Some kind of disk I/O error occurred */
            fprintf(stderr, "%s", " Some kind of disk I/O error occurred ");
            break;
        case SQLITE_CORRUPT    : /* The database disk image is malformed */
            fprintf(stderr, "%s", " The database disk image is malformed ");
            break;
        case SQLITE_NOTFOUND    :/* Unknown opcode in sqlite3_file_control() */
            fprintf(stderr, "%s", " Unknown opcode in sqlite3_file_control() ");
            break;
        case SQLITE_FULL       : /* Insertion failed because database is full */
            fprintf(stderr, "%s", " Insertion failed because database is full ");
            break;
        case SQLITE_CANTOPEN   :   /* Unable to open the database file */
            fprintf(stderr, "%s", " Unable to open the database file ");
            break;
        case SQLITE_PROTOCOL    :/* Database lock protocol error */
            fprintf(stderr, "%s", " Database lock protocol error ");
            break;
        case SQLITE_EMPTY       :  /* Internal use only */
            fprintf(stderr, "%s", " Internal use only ");
            break;
        case SQLITE_SCHEMA      : /* The database schema changed */
            fprintf(stderr, "%s", " The database schema changed ");
            break;
        case SQLITE_TOOBIG      :  /* String or BLOB exceeds size limit */
            fprintf(stderr, "%s", " String or BLOB exceeds size limit ");
            break;
        case SQLITE_CONSTRAINT  :  /* Abort due to constraint violation */
            fprintf(stderr, "%s", " Abort due to constraint violation ");
            break;
        case SQLITE_MISMATCH    :   /* Data type mismatch */
            fprintf(stderr, "%s", " Data type mismatch ");
            break;
        case SQLITE_MISUSE      :   /* Library used incorrectly */
            fprintf(stderr, "%s", " Library used incorrectly ");
            break;
        case SQLITE_NOLFS       :   /* Uses OS features not supported on host */
            fprintf(stderr, "%s", " Uses OS features not supported on host ");
            break;
        case SQLITE_AUTH        :  /* Authorization denied */
            fprintf(stderr, "%s", " Authorization denied ");
            break;
        case SQLITE_FORMAT      :  /* Not used */
            fprintf(stderr, "%s", " Not used ");
            break;
        case SQLITE_RANGE       :  /* 2nd parameter to sqlite3_bind out of range */
            fprintf(stderr, "%s", " 2nd parameter to sqlite3_bind out of range ");
            break;
        case SQLITE_NOTADB      :   /* File opened that is not a database file */
            fprintf(stderr, "%s", " File opened that is not a database file ");
            break;
        case SQLITE_NOTICE      :   /* Notifications from sqlite3_log() */
            fprintf(stderr, "%s", " Notifications from sqlite3_log() ");
            break;
        case SQLITE_WARNING     :   /* Warnings from sqlite3_log() */
            fprintf(stderr, "%s", " Warnings from sqlite3_log() ");
            break;
        case SQLITE_ROW         :  /* sqlite3_step() has another row ready */
            fprintf(stderr, "%s", " sqlite3_step() has another row ready ");
            break;
        case SQLITE_DONE        :  /* sqlite3_step() has finished executing */
            fprintf(stderr, "%s", " sqlite3_step() has finished executing ");
            break;
    }
}





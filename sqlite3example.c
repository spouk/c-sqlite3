//
// Created by spouk on 27.06.18.
//
#include <stdio.h>
#include <sqlite3.h>

int main() {
    printf("Sqlite3 current version %s\n", sqlite3_libversion());
    return 0;
}
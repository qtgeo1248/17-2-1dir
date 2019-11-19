#include "direct.h"

int main(int argc, char *arbv[]) {
    char *test;
    if (argc == 1) {
        test = ".";
    } else {
        char buf[256];
        strcpy(buf, arbv[1]);
        test = buf;
    }
    printf("STATISTICS FOR: %s\n", test);

    int size = dir_size(test);
    if (size < 0) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    } else {
        printf("SIZE OF ALL REG FILES: %d bytes\n", size);
    }

    printf("\nLISTING ALL FILES REGULARLY\n");
    if (list_files_reg(test) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }

    printf("\nLISTING ALL FILES SPECIALLY\n");
    if (list_files_type(test) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }

    printf("\nLISTING ALL FILES RECURSIVELY\n");
    char tabs[20] = "   ";
    if (list_files_rec(test, tabs) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }

    size = dir_size_rec(test);
    if (size < 0) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    } else {
        printf("\nSIZE OF EVERYTHING INSIDE (excluding . and ..): %d bytes\n", size);
    }

    printf("\nDo the makefile with TROLL=true for the biggest troll ever :)\n");
}

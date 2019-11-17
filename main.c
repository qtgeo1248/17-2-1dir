#include "direct.h"

int main() {
    char test[256] = ".";
    printf("STATISTICS FOR: %s\n", test);

    int size = dir_size(test);
    if (size < 0) {
        printf("Errno: %s\n", strerror(errno));
        return 1;
    } else {
        printf("SIZE OF ALL REG FILES: %d bytes\n", size);
    }

    printf("\nLISTING ALL FILES REGULARLY\n");
    if (list_files_reg(test) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return 1;
    }

    printf("\nLISTING ALL FILES SPECIALLY\n");
    if (list_files_type(test) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return 1;
    }

    printf("\nLISTING ALL FILES RECURSIVELY\n");
    char tabs[20] = "   ";
    if (list_files_rec(test, tabs) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return 1;
    }

    size = dir_size_rec(test);
    if (size < 0) {
        printf("Errno: %s\n", strerror(errno));
        return 1;
    } else {
        printf("\nSIZE OF EVERYTHING INSIDE (excluding . and ..): %d bytes\n", size);
    }

    printf("\nDo the makefile with TROLL=true for the biggest troll ever :)\n");
}

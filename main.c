#include "direct.h"

int main() {
    DIR *direct;
    struct dirent *file;
    char test[256] = ".";
    printf("STATISTICS FOR: %s\n", test);

    printf("\nLISTING ALL FILES REGULARLY\n");
    if (list_files_reg(test) > 0) {
        printf("Errno: %s\n", strerror(errno));
    }

    printf("\nLISTING ALL FILES SPECIALLY\n");
    if (list_files_type(test) > 0) {
        printf("Errno: %s\n", strerror(errno));
    }


}

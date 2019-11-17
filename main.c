#include "direct.h"

int main() {
    printf("Listing All Files Regularly:\n");
    char *test;
    strcpy(test, ".");
    list_files_reg(".");

    printf("\nListing All Files Specially:\n");
    //doing directories first
    DIR *direct;
    struct dirent *file;
    if (!(direct = opendir("."))) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }
    printf("Directories:\n");
    while (file = readdir(direct)) {
        if (file->d_type == DT_DIR) {
            printf("\t%s\n", file->d_name);
        }
    }
    //doing files next
    closedir(direct);
    if (!(direct = opendir("."))) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }
    printf("Files:\n");
    while (file = readdir(direct)) {
        if (file->d_type == DT_REG) {
            printf("\t%s\n", file->d_name);
        }
    }
}

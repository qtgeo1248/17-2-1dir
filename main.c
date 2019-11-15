#include "direct.h"

int main() {
    printf("Listing All Files Regularly:\n");
    DIR *direct;
    if (!(direct = opendir("."))) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }

    struct dirent *file;
    while (file = readdir(direct)) {
        printf("\t%s\ttype: %c\n", file->d_name, file->d_type);
    }

    printf("\nListing All Files Specially:\n");
    closedir(direct);
    //doing directories first
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

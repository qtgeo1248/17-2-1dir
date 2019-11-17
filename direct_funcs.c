#include "direct.h"

int list_files_reg(char *dir) {
    DIR *direct;
    if (!(direct = opendir(dir))) {
        return errno;
    }

    struct dirent *file;
    while ((file = readdir(direct))) {
        printf("\t%s\n", file->d_name);
    }
    return 0;
}

int list_files_type(char *dir) {
    //doing directories first
    DIR *direct;
    if (!(direct = opendir(dir))) {
        return errno;
    }
    printf("Directories:\n");
    struct dirent *file;
    while ((file = readdir(direct))) {
        if (file->d_type == DT_DIR) {
            printf("\t%s\n", file->d_name);
        }
    }

    //doing files next
    closedir(direct);
    if (!(direct = opendir(dir))) {
        return errno;
    }
    printf("Files:\n");
    while ((file = readdir(direct))) {
        if (file->d_type == DT_REG) {
            printf("\t%s\n", file->d_name);
        }
    }
    return 0;
}

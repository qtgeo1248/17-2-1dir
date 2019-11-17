#include "direct.h"

int list_files_reg(char *dir) {
    DIR *direct;
    if (!(direct = opendir(dir))) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }

    struct dirent *file;
    while (file = readdir(direct)) {
        printf("\t%s\n", file->d_name);
    }
    return 0;
}

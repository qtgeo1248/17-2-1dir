#include "direct.h"

int main() {
    printf("Listing All Files Regularly:\n");
    DIR *direct;
    if (!(direct = opendir("."))) {
        printf("Errno: %s\n", strerror(errno));
    }

    struct dirent *file;
    while (file = readdir(direct)) {
        printf("\t%s\n", file->d_name);
    }
}

#include "direct.h"

int dir_size(char *dir) {
    DIR *direct;
    if (!(direct = opendir(dir))) {
        return -1;
    }

    struct dirent *file;
    int size = 0;
    while ((file = readdir(direct))) {
        if (file->d_type == DT_REG) {
            char true_name[1000] = "";
            strcat(true_name, dir);
            strcat(true_name, "/");
            strcat(true_name, file->d_name);

            struct stat info;
            if (stat(true_name, &info) < 0) {
                return -1;
            }
            size = size + info.st_size;
            strcpy(true_name, "");
        }
    }
    closedir(direct);
    return size;
}

int list_files_reg(char *dir) {
    DIR *direct;
    if (!(direct = opendir(dir))) {
        return -1;
    }

    struct dirent *file;
    while ((file = readdir(direct))) {
        printf("\t%s\n", file->d_name);
    }
    return 0;
    closedir(direct);
}

int list_files_type(char *dir) {
    //doing directories first
    DIR *direct;
    if (!(direct = opendir(dir))) {
        return -1;
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
        return -1;
    }
    printf("Files:\n");
    while ((file = readdir(direct))) {
        if (file->d_type == DT_REG) {
            printf("\t%s\n", file->d_name);
        }
    }
    closedir(direct);
    return 0;
}

int list_files_rec(char *dir, char *tabs) {
    DIR *direct;
    if (!(direct = opendir(dir))) {
        return -1;
    }

    struct dirent *file;
    while ((file = readdir(direct))) {
        printf("%s%s\n", tabs, file->d_name);
        if ((file->d_type == DT_DIR) && (strcmp(file->d_name, ".") != 0) && (strcmp(file->d_name, "..") != 0)) {
            char true_name[1000] = "";
            strcat(true_name, dir);
            strcat(true_name, "/");
            strcat(true_name, file->d_name);
            char newtabs[50];
            strcpy(newtabs, tabs);
            strcat(newtabs, "   ");
            list_files_rec(true_name, newtabs);
        }
    }
    closedir(direct);
    return 0;
}

int dir_size_rec(char *dir) {
    DIR *direct;
    if (!(direct = opendir(dir))) {
        return -1;
    }

    struct dirent *file;
    int size = 0;
    while ((file = readdir(direct))) {
        if (file->d_type == DT_REG) {
            char true_name[1000] = "";
            strcat(true_name, dir);
            strcat(true_name, "/");
            strcat(true_name, file->d_name);

            struct stat info;
            if (stat(true_name, &info) < 0) {
                return -1;
            }
            size = size + info.st_size;
            strcpy(true_name, "");
        }
        if ((file->d_type == DT_DIR) && (strcmp(file->d_name, ".") != 0) && (strcmp(file->d_name, "..") != 0)) {
            char true_name[1000] = "";
            strcat(true_name, dir);
            strcat(true_name, "/");
            strcat(true_name, file->d_name);
            size += dir_size_rec(true_name);
        }
    }
    closedir(direct);
    return size;
}

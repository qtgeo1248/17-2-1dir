#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int list_files_reg(char *dir);
int list_files_type(char *dir);
int dir_size(char *dir);
int list_files_rec(char *dir, char *tabs);
int dir_size_rec(char *dir);

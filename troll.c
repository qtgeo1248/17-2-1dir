#include "direct.h"

int main() {
    printf("LISTING ALL FILES TROLLILY\n");
    char test[256] = "/Users";
    char tabs[1000] = "   ";
    if (list_files_rec(test, tabs) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}

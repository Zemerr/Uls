#include "../inc/header.h"

char **mx_file_arr(char **files, int size) {
    char **reg_file = NULL;
    int count = mx_files_quantity(files, 1);
    int i = 0;
    int q = 0;
    struct stat buf;
   
    mx_bubble_sort(files, size);
    reg_file = (char **)malloc(sizeof(char *) * (count + 1));
        for (i = 0; files[i]; i++) {
            if (lstat(files[i], &buf) < 0) {
                 mx_print_error_file(files[i]);
            }            
            else if ((buf.st_mode & S_IFDIR) != S_IFDIR) {
                reg_file[q] = mx_strdup(files[i]);
                q++;
            }
        }
        reg_file[q] = NULL;
        return reg_file;
}

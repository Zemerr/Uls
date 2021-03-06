#include "header.h"

static int files_count(DIR *dirp, char trig) {
    struct dirent *entry;
    int count = 0;

    entry = readdir(dirp);
    while (entry) {
        if (((*entry).d_name[1] != '\0' && (*entry).d_name[1] != '.')
            && trig == 'A') {
            count++;
        }
        else if (trig == 'a')
            count++;
        else {
            if ((*entry).d_name[0] != '.')
                count++;
        }
        entry = readdir(dirp);
    }
    closedir(dirp);
    return count;
}

static char **obj_arr(DIR *dirp, struct dirent *ent, char **arr, char trig) {
    for (int i = 0; ent;) {
        if (((*ent).d_name[1] != '\0' && (*ent).d_name[1] != '.')
            && trig == 'A') {
            arr[i] = mx_strdup((*ent).d_name);
            i++;
        }
        else if (trig == 'a') {
            arr[i] = mx_strdup((*ent).d_name);
            i++;
        }
        else {
            if ((*ent).d_name[0] != '.') {
                arr[i] = mx_strdup((*ent).d_name);
                i++;
            }
        }
        ent = readdir(dirp);
    }
    return arr;
}

static void error_print(DIR *dirp, char *dir_name) {
    char **error = NULL;
    int i;

    if (!dirp) {
        if (dir_name[mx_strlen(dir_name)-1] != '/') {
            error = mx_strsplit(dir_name, '/');
            i = 0;
            while (error[i] != NULL)
                i++;
            mx_printstr_err("uls: ");
            perror(error[i-1]);
            mx_del_strarr(&error);
        }
        else {
            mx_printstr_err("uls:");
            perror(" ");
        }
    }
}

char **mx_files_in_dir(char *dir_name, char trig, t_flags *flags) {
    DIR *dirp = opendir(dir_name);
    struct dirent *entry;
    char **arr = NULL;
    int count = 0;

    error_print(dirp, dir_name);
    if (dirp != NULL) {
        count = files_count(dirp, trig);
        if (count == 0)
            return NULL;
        dirp = opendir(dir_name);
        arr = (char **)malloc(sizeof(char *) * (count + 1));
        entry = readdir(dirp);
        arr = obj_arr(dirp, entry, arr, trig);
        arr[count] = NULL;
        closedir(dirp);
        if (count > 1 && (*flags).f == 0)
            mx_flag_sort(dir_name, arr, count, flags);
    }
    return arr;
}

#include "../inc/header.h"


char *mx_create_path(char *files, char *dir_name) {
	char *path = NULL;

    if (files[0] != '/') {
        path = mx_strjoin(dir_name, "/");
        path = mx_strjoin_two(path, files);
    }
    else
        path = files;
    return path;
}



t_sort *mx_pasre_struct(char **files, char *file_name, int dir_count) {
	t_sort *info_file = (t_sort *)malloc(sizeof(t_sort) * (dir_count));
	struct stat sb;

	mx_memset(info_file, 0, sizeof(t_sort));

	for (int i = 0; i < dir_count; i++) {
		char *path_name = mx_create_path(files[i], file_name);

		info_file[i].name = mx_strdup(files[i]);
		info_file[i].path = mx_strdup(path_name);
		lstat(path_name, &sb);
		if (files[i][0] != '/')
			free(path_name);
		info_file[i].size = sb.st_size;
	}
	return info_file;
}

void mx_swap_struct(t_sort *info_file_1, t_sort *info_file_2) {
	t_sort tmp = *info_file_1;
	*info_file_1 = *info_file_2;
	*info_file_2 = tmp;
}

static void swap(char **s1, char **s2) {
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void mx_dell_stuct(t_sort **info_file, int dir_count) {
    if (info_file && *info_file) {
        for (int i = 0; i < dir_count; i++) {
        	mx_strdel(&(*info_file)[i].name);
        	mx_strdel(&(*info_file)[i].path);
        }
        free(*info_file);
        *info_file = NULL;
    }
}

void mx_sort_S(char **files, int dir_count, char *file_name) {
	int i = 0;
	int size = dir_count;
	t_sort *info_file = mx_pasre_struct(files, file_name, dir_count);

	while (i < size) {
		if (info_file[i].size < info_file[i + 1].size) {
			swap(&files[i], &files[i + 1]);
			mx_swap_struct(&info_file[i], &info_file[i + 1]);		
		}
		i++;
		if (i == size - 1) {
			i = 0;
			size--;
		} 
	}
	mx_dell_stuct(&info_file, dir_count);
}



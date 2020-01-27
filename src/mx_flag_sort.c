#include "../inc/header.h"

static char *filepath(char *file_name, char *file) {
	char *str = file_name;
	char *path = NULL;

	if (mx_strcmp(file_name, "/") != 0)
		str = mx_strjoin(file_name, "/");
	path = mx_strjoin(str, file);
		if (mx_strcmp(file_name, "/") != 0)
			mx_strdel(&str);
	return path;
}

static struct stat *obj_info(char *file_name, char **files, int size) {
	struct stat *info = (struct stat *)malloc(sizeof(struct stat) * (size));
	char *path = NULL;

	for (int i = 0; i < size; i++) {
		path = filepath(file_name, files[i]);
		lstat(path, &info[i]);
		mx_strdel(&path);
	}
	return info;
}

void mx_flag_sort(char *file_name, char **files, int size, t_flags *flags) {
	struct stat buf_swap;
	char *swap = NULL;
	struct stat *buf = NULL;

	mx_bubble_sort(files, size);
	buf = obj_info(file_name, files, size);
		for (int j = 0; j < size - 1; j++) {
			for (int i = j + 1; i < size; i++) {
					if ((*flags).t == 1) {
						if (buf[i].st_mtime > buf[j].st_mtime) {
							buf_swap = buf[j];
							swap = files[j];
							buf[j] = buf[i];
							files[j] = files[i];
							buf[i] = buf_swap;
							files[i] = swap;
						}
						if (buf[i].st_mtime == buf[j].st_mtime) {
							if (mx_strcmp(files[i], files[j]) < 0) {
								buf_swap = buf[j];
								swap = files[j];
								buf[j] = buf[i];
								files[j] = files[i];
								buf[i] = buf_swap;
								files[i] = swap;
							}
						}
					}
					else if ((*flags).S == 1) {
						if (buf[i].st_size > buf[j].st_size) {
							buf_swap = buf[j];
							swap = files[j];
							buf[j] = buf[i];
							files[j] = files[i];
							buf[i] = buf_swap;
							files[i] = swap;
						}
						if (buf[i].st_size == buf[j].st_size) {
							if (mx_strcmp(files[i], files[j]) < 0) {
								buf_swap = buf[j];
								swap = files[j];
								buf[j] = buf[i];
								files[j] = files[i];
								buf[i] = buf_swap;
								files[i] = swap;
							}
						}
					}
			}
		}
		// if ((*flags).t == 1)
			// mx_bubble_sort(files, size);
		free(buf);
}

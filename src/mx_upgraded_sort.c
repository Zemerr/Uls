#include "header.h"

static long long sort_parametr(t_flags *flags, struct stat *info, int index) {
	if ((*flags).S == 1)
		return info[index].st_size;
	else if ((*flags).t == 1) {
		if ((*flags).u == 1)
			return info[index].st_atime;
		return info[index].st_mtime;
	}
	return 0;
}

static void swap(struct stat *buf, char **files, int i, int j) {
	char *swap = files[j];
	struct stat buf_swap = buf[j];

	buf[j] = buf[i];
	files[j] = files[i];
	buf[i] = buf_swap;
	files[i] = swap;
}

void mx_upgraded_sort(struct stat *buf, t_flags *flags, char **files) {
	long long p1;
	long long p2;

	for (int j = 0; files[j + 1]; j++) {
		for (int i = j + 1; files[i]; i++) {
				p1 = sort_parametr(flags, buf, i);
				p2 = sort_parametr(flags, buf, j);
					if ((*flags).r == 1) {
						if (p1 < p2) {
							swap(buf, files, i, j);
						}
						if (p1 == p2) {
							if (mx_strcmp(files[i], files[j]) > 0) {
								swap(buf, files, i, j);
							}
						}
					}
					else {
						if (p1 > p2) {
							swap(buf, files, i, j);
						}
						if (p1 == p2) {
							if (mx_strcmp(files[i], files[j]) < 0) {
								swap(buf, files, i, j);
							}
						}
					}
		}
	}
}

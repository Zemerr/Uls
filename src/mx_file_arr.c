#include "../inc/header.h"

char **mx_file_arr(char **files) {
	char **reg_file = NULL;
	int count = mx_files_quantity(files, 1);
	int i = 0;
	int q = 0;
	struct stat buf;


	reg_file = (char **)malloc(sizeof(char *) * count + 1);
		for (i = 0; files[i]; i++) {
			stat(files[i], &buf);
				if ((buf.st_mode & S_IFMT) == S_IFREG) {
					reg_file[q] = mx_str_copy(files[i]);
					q++;
				}
		}
		reg_file[q] = NULL;
		return reg_file;
}

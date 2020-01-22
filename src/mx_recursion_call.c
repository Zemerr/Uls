#include "../inc/header.h"

void mx_recursion_call(char **obj, t_flags *flags, char *file_name) {
	// printf("file_name = %s\n", file_name);
	char *str = mx_strjoin(file_name, "/");
	char *path = NULL;
	char **dir = NULL;
	struct stat buff;
	int count = 0;
	int q = 0;

	for (int i = 0; obj[i]; i++) {
		path = mx_strjoin(str, obj[i]);
		stat(path, &buff);
		if ((buff.st_mode & S_IFDIR) == S_IFDIR)
			count++;
	}
	if (count == 0) {
		return;
	}
	dir = (char **)malloc(sizeof(char *) * count + 1);
		for (int i = 0; obj[i]; i++) {
			path = mx_strjoin(str, obj[i]);
			stat(path, &buff);
				if ((buff.st_mode & S_IFMT) == S_IFDIR) {
					dir[q] = (char *)malloc(sizeof(char) * mx_strlen(obj[i]));
					dir[q] = mx_strncpy(dir[q], obj[i], mx_strlen(obj[i]));
					q++;
				}
		}
		dir[q] = NULL;
			for (int i = 0; dir[i]; i++) {
				path = mx_strjoin(str, dir[i]);
				write(1, path, mx_strlen(path));
				write(1, ":", 1);
				write(1, "\n", 1);
				mx_define_flags(path, flags);
				write(1, "\n", 1);
			}
}

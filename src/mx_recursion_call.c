#include "../inc/header.h"

void mx_recursion_call(char **obj, t_flags *flags, char *file_name) {
	char *str = NULL;
	char *path = NULL;
	char **dir = NULL;
	struct stat buff;
	int count = 0;
	int q = 0;


	if (!obj) {
		return;
	}
	if (mx_strcmp(file_name, "/") == 0)
		str = file_name;
	else
		str = mx_strjoin(file_name, "/");
	for (int i = 0; obj[i]; i++) {
			path = mx_strjoin(str, obj[i]);
			lstat(path, &buff);
			if ((buff.st_mode & S_IFLNK) != S_IFLNK) {
				if ((buff.st_mode & S_IFDIR) == S_IFDIR)
					count++;
			}
			mx_strdel(&path);
	}
	// system("leaks uls");
	dir = (char **)malloc(sizeof(char *) * (count + 1));
		for (int i = 0; obj[i]; i++) {
				path = mx_strjoin(str, obj[i]);
				lstat(path, &buff);
					if ((buff.st_mode & S_IFLNK) != S_IFLNK) {
						if ((buff.st_mode & S_IFMT) == S_IFDIR) {
							dir[q] = mx_strdup(obj[i]);
							q++;
						}
					}
					mx_strdel(&path);
		}
		dir[q] = NULL;
		// mx_del_strarr(&obj);
			for (int i = 0; dir[i]; i++) {
					path = mx_strjoin(str, dir[i]);
					write(1, "\n", 1);
					write(1, path, mx_strlen(path));
					write(1, ":", 1);
					write(1, "\n", 1);
					mx_define_flags(path, flags);
					mx_strdel(&path);
			}
			mx_del_strarr(&dir);
			mx_strdel(&str);
			// system("leaks uls");
}

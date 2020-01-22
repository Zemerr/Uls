#include "../inc/header.h"

char mx_file_mode_check(char *file, char *file_name) {
	//перевіряємо чи отриманий файл - звичайний, чи папка;
	char *filepath1 = NULL;
	char *filepath2 = file;
	struct stat buf;
	if (mx_strcmp(file_name, file) != 0) {
		filepath1 = mx_strjoin(file_name, "/");
		filepath2 = mx_strjoin(filepath1, file);
	}
	// printf("%s    %s\n", file, file_name);
	lstat(filepath2, &buf);
		switch (buf.st_mode & S_IFMT)
		{
			case (S_IFSOCK):
				return 's';
			case (S_IFLNK):
				return 'l';
			case (S_IFREG):
				if ((buf.st_mode & S_IXUSR) == S_IXUSR) {
					if ((buf.st_mode & S_ISUID) == S_ISUID)
						return 'u';
					if ((buf.st_mode & S_ISGID) == S_ISGID)
						return 'g';
					return 'e';
				}
				else
					return 'f';
			case (S_IFBLK):
				return 'b';
			case (S_IFDIR):
				if ((buf.st_mode & S_ISVTX) == S_ISVTX
					&& (buf.st_mode & S_IWOTH) == S_IWOTH) {
					return 'x';
				}
				if ((buf.st_mode & S_IWOTH) == S_IWOTH)
					return 'n';
				return 'd';
			case (S_IFCHR):
				return 'c';
			case (S_IFIFO):
				return 'p';
		}
		return '-';
}

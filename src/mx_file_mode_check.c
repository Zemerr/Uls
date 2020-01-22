#include "../inc/header.h"

char mx_file_mode_check(char *file) {
	//перевіряємо чи отриманий файл - звичайний, чи папка;
	struct stat buf;

	stat(file, &buf);
		switch (buf.st_mode & S_IFMT)
		{
			case (S_IFSOCK):
				return 's';
			case (S_IFLNK):
				return 'l';
			case (S_IFREG):
				return 'f';
			case (S_IFBLK):
				return 'b';
			case (S_IFDIR):
				return 'd';
			case (S_IFCHR):
				return 'c';
			case (S_IFIFO):
				return 'p';
		}
		return '-';
}

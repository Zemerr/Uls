#include "../inc/header.h"

int mx_file_mode_check(char *file) {
	//перевіряємо чи отриманий файл - звичайний, чи папка;
	struct stat buf;

	stat(file, &buf);
		if ((buf.st_mode & S_IFREG) == S_IFREG) {
			return 1;
		}
		if ((buf.st_mode & S_IFDIR) == S_IFDIR)
			return 2;
		return 0;
}

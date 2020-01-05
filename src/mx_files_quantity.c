#include "../inc/header.h"

int mx_files_quantity(char **files, int trig) {
	//визначення кількості звичайних файлів (трігер - 1),
	//або кількості папок/директорій (трігер - 2);
	int count = 0;

	if (trig == 1) {
		for (int i = 0; files[i]; i++) {
			if (mx_file_mode_check(files[i]) == 1) {
				count += 1;
			}
		}
	}
	if (trig == 2) {
		for (int i = 0; files[i]; i++) {
			if (mx_file_mode_check(files[i]) == 2)
				count += 1;
		}
	}
	return count;
}

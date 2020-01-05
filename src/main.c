#include "../inc/header.h"

static char *flags_check(char **argv, char **files) {
	char *flags = NULL;
	int q = 0;
	int j = 1;

	files = (char **)malloc(sizeof(char *) * argc);
		for ( ; argv[j]; j++) {
			if (argv[j][0] == '-')
				
			files[q] = (char *)malloc(sizeof(char) * mx_strlen(argv[j]));
			files[q] = mx_str_copy(argv[j]);
			q++;
		}
		files[q] = NULL;
}

int main(int argc, char **argv) {
	char **files = NULL;

	if (argc == 1) {
		//якщо аргумента немає, працюємо з директорією, де знаходимось;
		mx_files_in_dir(".");
	}
	if (argc > 1) {
		//якщо є аргументи, записуємо їх в масив;
		flags_check(argv, files);
		mx_file_specified(files);
	}
	mx_del_strarr(&files);
	// system ("leaks uls");
}

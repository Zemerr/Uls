#include "../inc/header.h"

static char *flags_fill_in(char **argv) {
	//створюю строку на 38 символів (максимальна кількість флагів),
	//записую в неї ті флаги, які вводяться;
	char *flags = NULL;
	int a = 0;

	flags = (char *)malloc(sizeof(char) * 38);
		for (int j = 1; argv[j] != NULL; j++) {
			if (argv[j][0] == '-') {
				for (int i = 1; argv[j][i] != '\0'; i++) {
					flags[a] = argv[j][i];
					a++;
				}
			}
		}
		return flags;
}

static char **files_fill_in(int argc, char **argv) {
	//створюю масив введенних файлів;
	char **files = NULL;
	int q = 0;
	int j = 1;

	files = (char **)malloc(sizeof(char *) * argc);
		for ( ; argv[j]; j++) {
			files[q] = mx_str_copy(argv[j]);
			q++;
		}
		files[q] = NULL;
		return files;
}

int main(int argc, char **argv) {
	char **files = NULL;
	char *flags = NULL;

	if (argc == 1) {
		//якщо аргумента немає, працюємо з директорією, де знаходимось;
		mx_files_in_dir(".");
	}
	if (argc > 1) {
		//якщо є аргументи, записуємо їх в масив;
		files = files_fill_in(argc, argv);
		flags = flags_fill_in(argv);
		mx_file_specified(files);
		mx_del_strarr(&files);
	}
	//test
	// system ("leaks uls");
}

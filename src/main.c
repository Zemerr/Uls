#include "../inc/header.h"

static int files_count(int argc, char **argv) {
	int count = 0;

	if (argc == 0)
		return 0;
	for (int i = 1; argv[i]; i++) {
		if (argv[i][0] != '-') {
			count++;
		}
	}
	return count;
}

static int flags_count(char **argv) {
	//визначення кількості флагів;
	int count = 0;

	for (int j = 1; argv[j] != NULL; j++) {
		if (argv[j][0] == '-') { //аргумент починається з "-" - флаг;
			for (int i = 1; argv[j][i] != '\0'; i++) {
					if (argv[j][i] == '-') {//якщо знайшли 2 "-" в
						return -1;         //одному аргументі;
					}
					count++;
			}
		}
	}
	return count;	
}

static char *flags_fill_in(char **argv, int count) {
	char *flags = NULL;
	int o = 0;

	if (count == -1) {
		return NULL;
	}
	flags = (char *)malloc(sizeof(char) * count + 1);
		for (int j = 1; argv[j] != NULL; j++) {
			if (argv[j][0] == '-') {
				for (int i = 1; argv[j][i] != '\0'; i++, o++) {
					flags[o] = argv[j][i];
				}
			}
		}
		flags[o] = '\0';

		return flags;
}

static t_flags *flags_filter(char **argv, int count) {
	char *str = flags_fill_in(argv, count);
	t_flags *flag = (t_flags *)malloc(sizeof(t_flags));

	for (int i = 0; str[i] != '\0'; i++) {
		switch (str[i])
		{
			case('A'):
				if ((*flag).a == 0) {
					(*flag).A = 1;
				}
				break;
			case('a'):
				(*flag).a = 1;
				(*flag).A = 0;
				break;
			case('l'):
				(*flag).l = 1;
				break;
		}
	}
	return flag;
}

// static char *flags_fill_in(char **argv, int count) {
// 	char *flags = NULL;
// 	int o = 0;

// 	if (count == -1) {
// 		return NULL;
// 	}
// 	flags = (char *)malloc(sizeof(char) * count + 1);
// 		for (int j = 1; argv[j] != NULL; j++) {
// 			if (argv[j][0] == '-') {
// 				for (int i = 1; argv[j][i] != '\0'; i++, o++) {
// 					flags[o] = argv[j][i];
// 				}
// 			}
// 		}
// 		flags[o] = '\0';

// 		return flags;
// }

static char **files_fill_in(int argc, char **argv) {
	//створюю масив введенних файлів(флаги не враховуються);
	char **files = (char **)malloc(sizeof(char *) * argc);
	int q = 0;
	int j = 1;

		for ( ; argv[j]; j++) {
			files[q] = mx_str_copy(argv[j]);
			q++;
		}
		files[q] = NULL;
		return files;
}

int main(int argc, char **argv) {
	int filec = files_count(argc, argv); 
	char **files = NULL;
	int flagc = flags_count(argv);
	t_flags *flags = flags_filter(argv, flagc);


	if (flagc == -1) {
			write(2, "usage: uls [-l] [file ...]\n",
				mx_strlen("usage: uls [-l] [file ...]\n"));//якщо в одному аргументі
				return 0;								//2 флага і між ними "-"	
	}
	if (filec == 0) {
		// printf("there is no given file\n");
		//якщо аргумента немає, працюємо з директорією, де знаходимось;
		mx_define_flags(".", flags);
		// mx_files_in_dir(".");
	}
	if (filec != 0) {
		files = files_fill_in(argc, (argv));
		// printf("there is some files\n");
			// for (int i = 0; files[i]; i++) {
			// 	printf("%s, ", files[i]);
			// }
		mx_file_specified(files, flags, ".");
		mx_del_strarr(&files);
	}
	// system ("leaks uls");
}

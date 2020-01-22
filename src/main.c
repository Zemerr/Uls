#include "../inc/header.h"

static int files_count(int argc, char **argv) {
	int count = 0;

	if (argc == 0)
		return 0;
	for (int i = 1; argv[i]; i++) {
		if (count > 0 && argv[i][0] == '-') { //if there is such mistake as "./uls -a inc -R"
			return -1;						 //the output should be :
		}								    //"./uls -R: No such file or directory"
		if (argv[i][0] != '-') {		   //and uls continues working;
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

static char **files_fill_in(int argc, char **argv) {
	//створюю масив введенних файлів(флаги не враховуються);
	char **files = (char **)malloc(sizeof(char *) * argc);
	int q = 0;
	int j = 1;

		for ( ; argv[j]; j++) {
			if (argv[j][0] != '-')
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
	t_flags *flags = mx_flags_filter(argv, flagc);

	if (flagc == -1 || filec == -1) {
			write(2, "usage: uls [-lGRAa] [file ...]\n",
				mx_strlen("usage: uls [-lGRAa] [file ...]\n"));//error for such cases:
				return 0;	                    //1. "./uls -a-A"; 2. "./uls -a inc -l"
	}
	if (filec == 0) {                //if there is no files/directories among arguments
		mx_define_flags(".", flags);//but may be some flags;
	}
	if (filec != 0) {                               //if there is any file/directory
		files = files_fill_in(argc, (argv));       //from among arguments except flags;
		mx_file_specified(files, flags, ".");
	}
}

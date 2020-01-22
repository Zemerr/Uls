#include "../inc/header.h"

void mx_colour_out(char *file, char *file_name) {
	char *str = NULL;

	write(1, "\33[0m", mx_strlen("\33[0m"));
	// printf("file %s is %c\n", file, mx_file_mode_check(file, file_name));
	switch(mx_file_mode_check(file, file_name))
	{
		case('d'):
			str = mx_strjoin("\33[0;34m", file);
			break;
		case('f'):
			str = file;
			break;
		case('l'):
			str = mx_strjoin("\33[0;35m", file);
			break;
		case('e'):
			str = mx_strjoin("\33[0;31m", file);
			break;
		case('c'):
			str = mx_strjoin("\33[0;34;43m", file);
			break;
		case('b'):
			str = mx_strjoin("\33[0;34;46m", file);
			break;
		case('x'):
			str = mx_strjoin("\33[0;30;42m", file);
			break;
		case('u'):
			str = mx_strjoin("\33[0;30;41m", file);
			break;
		case('s'):
			str = mx_strjoin("\33[0;32m", file);
			break;
		case('g'):
			str = mx_strjoin("\33[0;30;44m", file);
			break;
		case('n'):
			str = mx_strjoin("\33[0;30;41m", file);
			break;
		case('-'):
			str = mx_strjoin("\33[0;34m", file);
			break;
	}
	write (1, str, mx_strlen(str));
	write(1, "\33[0m", mx_strlen("\33[0m"));
}

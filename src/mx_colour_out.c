#include "../inc/header.h"

void mx_colour_out(char *file) {
	char *str = NULL;

	write(1, "\33[0;37m", mx_strlen("\33[0;37m"));
	// printf("%c\n", mx_file_mode_check(file));
	switch(mx_file_mode_check(file))
	{
		case('d'):
			str = mx_strjoin("\33[0;34m", file);
			break;
		case('f'):
			str = file;
			break;
		case('l'):
			str = mx_strjoin("\33[0;36m", file);
			break;
	}
	write (1, str, mx_strlen(str));
}

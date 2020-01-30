#include "../inc/header.h"

static void win_size(int size, int w_s) {
	if (w_s < (size)) {
		w_s = mx_get_ws();
			if (isatty(1) == 0)
				w_s = 79;
			write(1, "\n", 1);
	}
}

static void flag_m(char **files, int w_s, char *file_name, t_flags *flag) {
	int size;

	for (int i = 0; files[i]; i++) {
		size = mx_strlen(files[i]) + 2;
			if (!files[i + 1])
				size -= 2;
			win_size(size, w_s);
				if ((*flag).G == 1)
					mx_colour_out(files[i], file_name);
				else
					write (1, files[i], mx_strlen(files[i]));
				if (files[i + 1])
					write(1, ", ", 2);
				else
					write(1, "\n", 1);
				w_s -= size;
	}
}

void mx_simple_out(char **files, t_flags *flag, char *file_name) {
	int w_s = mx_get_ws();
	int size;

	if (isatty(1) == 0)
		w_s = 79;
	if ((*flag).m == 1)
		flag_m(files, w_s, file_name, flag);
	else if ((*flag).one == 1) {
		for (int i = 0; files[i]; i++) {
			size = mx_strlen(files[i]);
				if ((*flag).G == 1)
					mx_colour_out(files[i], file_name);
				else
					write (1, files[i], size);
				write(1, "\n", 1);
		}
	}
}

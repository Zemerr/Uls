#include "../inc/header.h"

void mx_simple_out(char **files, t_flags *flag, char *file_name) {
	int w_s = mx_get_ws();
	int size;

	if (isatty(1) == 0)
		w_s = 79;
	for (int i = 0; files[i]; i++) {
		if ((*flag).m == 1) {
			size = mx_strlen(files[i]);
				if (w_s < (size + 2)) {
					w_s = mx_get_ws();
						if (isatty(1) == 0)
							w_s = 79;
						write(1, "\n", 1);
				}
				if ((*flag).G == 1)
					mx_colour_out(files[i], file_name);
				else
					write (1, files[i], size);
				if (files[i + 1])
					write(1, ", ", 2);
				else
					write(1, "\n", 1);
				w_s -= (size + 2);
		}
		else if ((*flag).one == 1) {
			size = mx_strlen(files[i]);
				if ((*flag).G == 1)
					mx_colour_out(files[i], file_name);
				else
					write (1, files[i], mx_strlen(files[i]));
				write(1, "\n", 1);
		}
	}
}

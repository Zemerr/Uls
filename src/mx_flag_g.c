#include "../inc/header.h"

static int max_len(char **arr) {
	//визначення довжини найдовшої назви файла; 
	int len = 0;

	for (int i = 0; arr[i]; i++) {
		if (mx_strlen(arr[i]) > len) {
			len = mx_strlen(arr[i]);
		}
	}
	return len;
}

static int get_rows(int count, int max_len, int w_s) {
	//визначення кількості рядків;
	int rows;
	int one_line = w_s / (max_len + 1);

	rows = count / one_line;
		if (count % one_line != 0)
			rows += 1;
	return rows;
}

static void spacing_print(int sp) {
	char c = ' ';

	while (sp > 0) {
		write(1, &c, 1);
		sp--;
	}
}

void mx_flag_g(char **arr, int count, char *file_name) {
	int m_l = max_len(arr);
	int w_s = mx_get_ws();
	int rows = get_rows(count, m_l, w_s);
	int wd_per_line = count / rows;
	int cycle = 0;
	int spacing = 0;
	int cur_len = 0;

	if (count % rows != 0)
		wd_per_line += 1;


	for (int j = 0; j < rows; j++) {
		cycle = 0;
			for (int i = j; cycle < wd_per_line && i < count; i += rows) {
				if (!arr[i])
					break;
				cur_len = mx_strlen(arr[i]);
				spacing = m_l - cur_len + 1;
					if (cycle + 1 == wd_per_line)
						spacing = 0;
					mx_colour_out(arr[i], file_name, NULL);
					spacing_print(spacing);
					cycle++;
			}
			w_s = mx_get_ws();
			write(1, "\n", 1);
	}
	// mx_del_strarr(&arr);
}

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

static void print_item(char *s, int sp, t_flags *flag) {
	//вивід назви файла і відповідної кількості спейсбарів після нього;
	char c = '\t';
	// printf("%s---\n", s);
	// mx_printstr(s);
	if ((*flag).G == 1)
		mx_colour_out(s);
	else
		write(1, s, mx_strlen(s));
	// printf("%d\t", mx_strlen(s));
		while (sp > 0) {
			// printf("%d\t", sp);
			write(1, &c, 1);
			sp -= 8;
		}
} 

static int get_rows(int count, int max_len, int w_s) {
	//визначення кількості рядків;
	int rows;
	int one_line = w_s / (((max_len / 8) * 8) + 8);

	rows = count / one_line;
		if (count % one_line != 0)
			rows += 1;
	return rows;
}

void mx_print_cols(char **arr, int count, t_flags *flag) {
	//вивід колонками;
	int m_l = max_len(arr);
	int cur_len = 0;
	int w_s = mx_get_ws();
	int spacing = 0;
	int rows = get_rows(count, m_l, w_s);
	int cycle = 0;
	int wd_per_line = count / rows;

	if (count % rows != 0)
		wd_per_line += 1;

	for (int j = 0; j < rows; j++) {
		cycle = 0;
		for (int i = j; cycle < wd_per_line && i < count; i += rows) {
			if (!arr[i])
				break;
			cur_len = mx_strlen(arr[i]);
			spacing = ((m_l / 8) * 8) - cur_len + 8;
			if (cycle + 1 == wd_per_line)
				spacing = 0;
			print_item(arr[i], spacing, flag);
			cycle++;
		}
		w_s = mx_get_ws();

		write(1, "\n", 1);
	}
	mx_del_strarr(&arr);
}

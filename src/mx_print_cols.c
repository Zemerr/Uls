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

static void print_item(char *s, int sp) {
	//вивід назви файла і відповідної кількості спейсбарів після нього;
	char c = ' ';

	mx_printstr(s);
		while (sp > 0) {
			write(1, &c, 1);
			sp--;
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

void mx_print_cols(char **arr, int count) {
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
		for (int i = j; cycle < wd_per_line && arr[i]; i += rows) {
			cur_len = mx_strlen(arr[i]);
			spacing = ((m_l / 8) * 8) - cur_len + 8;
			print_item(arr[i], spacing);
			cycle++;
		}
		w_s = mx_get_ws();
		write(1, "\n", 1);
	}
	mx_del_strarr(&arr);
}

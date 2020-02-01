#include "header.h"

static int max_len(char **arr) {
    int len = 0;

    for (int i = 0; arr[i]; i++) {
        if (mx_strlen(arr[i]) > len) {
            len = mx_strlen(arr[i]);
        }
    }
    return len;
}

static int get_rows(int count, int max_len) {
    int rows;
    int one_line = 0;
    int w_s = mx_get_ws();

    if (w_s <= (max_len + 1))
        return count;
    one_line = w_s / (max_len + 1);
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
    int rows = get_rows(count, m_l);
    int spacing = 0;

    for (int j = 0; j < rows; j++) {
        for (int i = j; i < count; i += rows) {
            if (!arr[i])
                break;
            spacing = m_l - mx_strlen(arr[i]) + 1;
                if ((i + rows) >= count)
                    spacing = 0;
                mx_colour_out(arr[i], file_name);
                spacing_print(spacing);
        }
        write(1, "\n", 1);
    }
}

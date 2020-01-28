#include "../inc/header.h"

static int max_len(char **arr) {
    int len = 0;

    for (int i = 0; arr[i]; i++) {
        if (mx_strlen(arr[i]) > len)
            len = mx_strlen(arr[i]);
    }
    return len;
}

static void print_item(char *s, int sp) {
    char c = '\t';

    write(1, s, mx_strlen(s));
        while (sp > 0) {
            write(1, &c, 1);
            sp -= 8;
        }
} 

static int get_rows(int count, int max_len, t_flags *flags) {
    int w_s = mx_get_ws();
    int rows;
    int one_line = 0;

    if (isatty(1) == 0) {
        if ((*flags).C == 1) {
            w_s = 79;
        }
    }
    if (w_s <= (((max_len / 8) * 8) + 8))
        return count;
    one_line = w_s / (((max_len / 8) * 8) + 8);
    rows = count / one_line;
        if (count % one_line != 0)
            rows += 1;
    return rows;
}

void mx_print_cols(char **arr, int count, t_flags *flags) {
    int m_l = max_len(arr);
    int spacing = 0;
    int rows = get_rows(count, m_l, flags);

    for (int j = 0; j < rows; j++) {
        for (int i = j; i < count; i += rows) {
            if (!arr[i])
                break;
            spacing = ((m_l / 8) * 8) - mx_strlen(arr[i]) + 8;
                if ((i + rows) >= count) {
                    spacing = 0;
                }
            print_item(arr[i], spacing);
        }
        write(1, "\n", 1);
    }
}

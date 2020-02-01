#include "header.h"

static char *build_num(double n, double buf_one,  double buf_two, char **n_t) {
    char *number = NULL;
    int my_num = n;

    buf_one = buf_two;
    if (buf_two - (int) buf_one >= 0.5) {
        buf_one = buf_one + 1;
    }
    if ((int) buf_one >= 10) {
        my_num = my_num + 1;
        buf_one = 0;
    }
    number = mx_itoa(my_num);
    if (my_num >= 10)
        return number;
    number = mx_strjoin_two(number, ".");
    *n_t = mx_itoa(buf_one);
    number = mx_strjoin_two(number, *n_t);
    return number;
}


static char *neccesary_num(double n) {
    int my_num = n;
    double buf_one = 0.0;
    double buf_two;
    char *number = NULL;
    char *number_two = NULL;

    if (n >= 10) {
            buf_one = n - my_num;
            if (buf_one >= 0.5)
                my_num = my_num + 1;
            number = mx_itoa(my_num);
        }
    else {
        buf_two = (n - (double) my_num) * 10;
        number = build_num(n, buf_one, buf_two, &number_two);
        if (malloc_size(number_two)) 
            mx_strdel(&number_two);
    }
    return number;
}

static void check_size(long i, char **num, char **str_out, double n) {
    if (i < 1000) { //B
        *num = mx_itoa(i);
        *str_out = mx_strjoin_two(*num, "B");
    }
    if (i >= 1000 && i < 1048576 ) { //K
        n = (double) i / (double) 1024;
        *str_out = neccesary_num(n);
        *str_out = mx_strjoin_two(*str_out, "K");
    }
    if (i >= 1048576 && i < 1073741824 ) { //Mb
        n = (double) i / (double) 1048576;
        *str_out = neccesary_num(n);
        *str_out = mx_strjoin_two(*str_out, "M");
    }
    if (i >= 1073741824 && i < 1099511627776 ) { //Gb
        n = (double) i / (double) 1073741824;
        *str_out = neccesary_num(n);
        *str_out = mx_strjoin_two(*str_out, "G");
    }
}

char *mx_for_flag_h(long i) {
    char *num = NULL;
    char *str_out = NULL;
    double n = 0;

    check_size(i, &num, &str_out, n);
    return str_out;
}

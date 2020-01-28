#include "../inc/header.h"

static char *neccesary_num(double n) {
    int my_num = 0;
    double buf_one;
    double buf_two;
    char *number = NULL;
    char *number_two = NULL;

    if (n >= 10) {
            my_num = n;
            buf_one = n - my_num;
            if (buf_one >= 0.5)
                my_num = my_num + 1;
            number = mx_itoa(my_num);
        }
        else {
            my_num = n;
            buf_two = (n - (double) my_num) * 10;
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
            number_two = mx_itoa(buf_one);
            number = mx_strjoin_two(number, number_two);
            if (malloc_size(number_two)) 
                mx_strdel(&number_two);
        }
    return number;
}



static char *for_flag_h(long i) {
    char *num = NULL;
    char *str_out = NULL;
    double n = 0;

    if (i < 1000) { //B
        num = mx_itoa(i);
        str_out = mx_strjoin_two(num, "B");
    }
    if (i >= 1000 && i < 1048576 ) {//K
        n = (double) i / (double) 1024;
        str_out = neccesary_num(n);
        str_out = mx_strjoin_two(str_out, "K");
    }
    if (i >= 1048576 && i < 1073741824 ) {
        //Mb
        n = (double) i / (double) 1048576;
        str_out = neccesary_num(n);
        str_out = mx_strjoin_two(str_out, "M");
    }
    if (i >= 1073741824 && i < 1099511627776 ) {
        //Gb
        n = (double) i / (double) 1073741824;
        str_out = neccesary_num(n);
        str_out = mx_strjoin_two(str_out, "G");
    }
    return str_out;
}




static void print_major(t_lens *my_lens, t_acl_trig *trigers) {
    int j = 0;

    if (my_lens->forth_len > my_lens->minor_major_len) {
        for (j = 0; j < my_lens->forth_len - my_lens->minor_major_len; j++) 
            mx_printstr(" ");
        }
    else 
        mx_printstr(" ");
    for (j = 0; j < my_lens->major_len - mx_intlen(trigers->major); j++)
        mx_printstr(" ");
    mx_printint(trigers->major);
    mx_printstr(",");
    mx_printstr(" ");
}

static void print_minor(t_lens *my_lens, t_acl_trig *trigers) {
    char *nbr = NULL;
    char *need_nul = NULL;
    char *binar = NULL;
    int n = 0;
    int j = 0;

    if (trigers->minor > 255) {
        nbr = mx_nbr_to_hex(trigers->minor);
        n = 8 - mx_strlen(nbr);
        need_nul = mx_strndup("0x00000000", n + 2);
        binar = mx_strjoin(need_nul, nbr);
        mx_printstr(binar);
    } 
    else {
        for (j = 0; j < my_lens->minor_len - mx_intlen(trigers->minor); j++)
            mx_printstr(" ");
        mx_printint(trigers->minor);
    }
    mx_strdel_three(&nbr, &need_nul, &binar);
}



void mx_print_size_mm(t_lens *lens, struct stat sb, t_acl_trig *trigers,
t_flags *flags) {
    char *num;
    if (trigers -> dev_flag == 1 && trigers->l_flag != 1) {
        print_major(lens, trigers);
        print_minor(lens, trigers);
        trigers -> dev_flag = 0;
    } 
    else {
        if (lens->flag_device == 1) {
            if (lens->forth_len < lens->minor_major_len) {
                for (int j = 0; j < lens->minor_major_len - mx_intlen(sb.st_size); j++) 
                    mx_printstr(" ");
            }
            mx_printint(sb.st_size);
        }

        else if (lens->flag_device != 1 && flags->h != 1) {
            for (int j = 0; j < lens->forth_len - mx_intlen(sb.st_size); j++)
                mx_printstr(" ");
             mx_printint(sb.st_size);
            }
        else if (flags->h == 1 && lens->flag_device != 1) {
            num = for_flag_h(sb.st_size);
            mx_printstr(" ");
            for (int j = 0; j < 4 - mx_strlen(num); j++)
                mx_printstr(" ");
            mx_printstr(num);
            mx_strdel(&num);
        }        
    }
    mx_printstr(" ");
}

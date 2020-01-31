#include "../inc/header.h"

static void print_major(t_lens *my_lens, t_acl_trig *trigers) {
    int j = 0;

    if (my_lens->forth_len > 8) {
        for (j = 0; j < my_lens->forth_len - 8; j++) 
            mx_printstr(" ");
        }
    for (j = 0; j < 3 - mx_intlen(trigers->major); j++)
        mx_printstr(" ");
    mx_printint(trigers->major);
    mx_printstr(",");
    mx_printstr(" ");
}

static void print_minor(t_acl_trig *trigers) {
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
        for (j = 0; j < 3 - mx_intlen(trigers->minor); j++)
            mx_printstr(" ");
        mx_printint(trigers->minor);
    }
    mx_strdel_three(&nbr, &need_nul, &binar);
}

static void print_size(char **num, t_lens *len, struct stat sb, t_flags *flag) {
     if (len->flag_device == 1) {
            if (len->forth_len < 8) {
                for (int j = 0; j < 8 - mx_intlen(sb.st_size); j++)
                    mx_printstr(" ");
            }
            mx_printint(sb.st_size);
        }
    else if (len->flag_device != 1 && flag->h != 1) {
        for (int j = 0; j < len->forth_len - mx_intlen(sb.st_size); j++)
            mx_printstr(" ");
            mx_printint(sb.st_size);
        }
    else if (flag->h == 1 && len->flag_device != 1) {
        *num = mx_for_flag_h(sb.st_size);
        mx_printstr(" ");
        for (int j = 0; j < 4 - mx_strlen(*num); j++)
            mx_printstr(" ");
        mx_printstr(*num);
        mx_strdel(&(*num));
    }
}


void mx_print_size_mm(t_lens *lens, struct stat sb, t_acl_trig *trigers,
t_flags *flags) {
    char *num;
    if (trigers -> dev_flag == 1 && trigers->l_flag != 1) {
        print_major(lens, trigers);
        print_minor(trigers);
        trigers -> dev_flag = 0;
    } 
    else {
        print_size(&num, lens, sb, flags);  
    }
    mx_printstr(" ");
}

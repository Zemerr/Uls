#include "../inc/header.h"

//static for_flag_h(int i) {
// if (i < 1024)
//     //B

// if (i >= 1024 && i < 1048576 )
//     //Kb
// if (i >= 1048576 && i < 1073741824 )
//     //Mb
// if (i >= 1073741824 && i < 1099511627776 )
//     //Gb

// }




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



void mx_print_size_mm(t_lens *lens, struct stat sb, t_acl_trig *trigers) {
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
        }
        else {
            for (int j = 0; j < lens->forth_len - mx_intlen(sb.st_size); j++)
                mx_printstr(" ");
            }
        
        mx_printint(sb.st_size);
    }
    mx_printstr(" ");
}

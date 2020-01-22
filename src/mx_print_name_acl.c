#include "../inc/header.h"

static void print_acl(struct stat sb, char *my_acl_line, t_lens *my_lens) {
    mx_printstr(my_acl_line);
    mx_printstr(" ");
    for (int j = 0; j < my_lens->first_len - mx_intlen(sb.st_nlink); j++) {
        mx_printstr(" ");
    }
    mx_printint(sb.st_nlink);
    mx_printstr(" ");
}

static void print_name(t_lens *my_lens, struct stat sb) {
    struct passwd *user_info = getpwuid(sb.st_uid);
    struct group *g_info = getgrgid(sb.st_gid);
    int j = 0;
    
    mx_printstr(user_info->pw_name);
    mx_printstr("  ");
    for (j = 0; j < my_lens->second_len - mx_strlen(user_info->pw_name); j++)
        mx_printstr(" ");
    if (g_info != NULL) {
        mx_printstr(g_info->gr_name);
        for (j = 0; j < my_lens->third_len - mx_strlen(g_info->gr_name); j++) 
            mx_printstr(" ");
    }
    else {
        mx_printint(user_info->pw_gid);
        for (j = 0; j < my_lens->third_len - mx_intlen(user_info->pw_gid); j++) 
            mx_printstr(" ");
    }
    mx_printstr("  ");
}


void mx_print_name_acl(struct stat sb, char *my_acl_line, t_lens *my_lens) {
    print_acl(sb, my_acl_line, my_lens);
    print_name(my_lens, sb);

}

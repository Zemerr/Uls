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

static void print_group(struct group *g_info, t_lens *m_l,
struct passwd *user_info) {
    int j = 0;

    if (g_info != NULL) {
        mx_printstr(g_info->gr_name);
        for (j = 0; j < m_l->third_len - mx_strlen(g_info->gr_name); j++) 
            mx_printstr(" ");
        }
        else {
            mx_printint(user_info->pw_gid);
            for (j = 0; j < m_l->third_len - mx_intlen(user_info->pw_gid); j++) 
                mx_printstr(" ");
        }
        mx_printstr("  ");
}



static void print_name(t_lens *my_lens, struct stat sb, t_flags *flags) {
    struct passwd *user_info = getpwuid(sb.st_uid);
    struct group *g_info = getgrgid(sb.st_gid);
    int j = 0;
    
    if (flags->g == 1 && flags->o == 1)
        mx_printstr("  ");

    if (flags->g != 1) {
        mx_printstr(user_info->pw_name);
        mx_printstr("  ");
    for (j = 0; j < my_lens->second_len - mx_strlen(user_info->pw_name); j++)
        mx_printstr(" ");
    }
    if (flags->o != 1) {
        print_group(g_info, my_lens, user_info);
    }
}


void mx_print_name_acl(struct stat sb, char *my_acl_line, t_lens *my_lens,
t_flags *flags) {
    print_acl(sb, my_acl_line, my_lens);
    print_name(my_lens, sb, flags);
}

#include "../inc/header.h"


static void acl_get_f(char *path_name_1, char *my_acl_line) {
    acl_t my_acl;
    char *text_acl;
    ssize_t len;
    ssize_t buflen;
    
    my_acl = acl_get_file(path_name_1, ACL_TYPE_EXTENDED);
    text_acl = acl_to_text(my_acl, &len);
    buflen = listxattr(path_name_1, NULL, 0, XATTR_NOFOLLOW);
    if (text_acl != NULL)
        my_acl_line[10] = '+';
    if (buflen > 0)
        my_acl_line[10] = '@';
    free(my_acl);
    if (malloc_size(text_acl))
        free(text_acl);
}


char *mx_for_flagl_two(struct stat sb, t_acl_trig *trigers, char *path_name_1,
char *my_acl_line) {
    mx_acl_line( sb, trigers, my_acl_line);
    acl_get_f(path_name_1, my_acl_line);
    if (trigers->dev_flag == 1) {
        trigers->minor = minor(sb.st_rdev);
        trigers->major = major(sb.st_rdev);
    }
    return my_acl_line;

}

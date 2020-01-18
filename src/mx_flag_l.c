#include "../inc/header.h"
#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <malloc/malloc.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <time.h>
#include <unistd.h>

void mx_flag_l(char **sort_arr, char *dir_name) {



    struct stat sb;

    char my_acl_line[] = "-----------";
    my_acl_line[10] = ' ';

    char *time = NULL;
    char **time_arr = NULL;
    char **hour_arr = NULL;
    char *hour;

    char *path_name_1 = NULL;
    char *path_name_2 = NULL;


    int l_flag = 0;
    int dev_flag = 0;

    unsigned int minor = 0;
    unsigned int major = 0;

    char *nbr = NULL;
    char *need_nul = NULL;
    char *binar = NULL;

    struct passwd *user_info = NULL;
    struct group *gruop_info;
    acl_t my_acl;
    char *text_acl;
    ssize_t len;
    ssize_t buflen;

    char buf_link[30];

    int first_len = 0;
    int second_len = 0;
    int third_len = 0;
    int forth_len = 0;
    int minor_len = 0;
    int major_len = 0;


    int minor_major_len = 0;
    
    

    int flag_device = 0;
    unsigned long long blocks = 0;
    

    for (int i = 0; sort_arr[i] != NULL; i++) {
        path_name_1 = mx_strjoin(dir_name, "/");
        path_name_2 = mx_strjoin(path_name_1, sort_arr[i]);



        lstat(path_name_2, &sb);
        if (first_len < mx_intlen(sb.st_nlink))
            first_len = mx_intlen(sb.st_nlink);
        user_info = getpwuid(sb.st_uid);
        if (second_len < mx_strlen(user_info->pw_name)) {
            second_len = mx_strlen(user_info->pw_name);
        }
        gruop_info = getgrgid(sb.st_gid);
        if (gruop_info != NULL) {
            if (third_len < mx_strlen(gruop_info->gr_name))
                third_len = mx_strlen(gruop_info->gr_name);
        }   
        else {
            if (third_len < mx_intlen(user_info->pw_gid))
                third_len = mx_intlen(user_info->pw_gid);
        }

         if (((sb.st_mode & S_IFCHR) == S_IFCHR || 
            (sb.st_mode & S_IFBLK) == S_IFBLK) && 
            (sb.st_mode & S_IFDIR) != S_IFDIR &&
            (sb.st_mode & S_IFREG) != S_IFREG && 
            (sb.st_mode & S_IFLNK) != S_IFLNK) {
            flag_device = 1; 
            minor = minor(sb.st_rdev);
            major = major(sb.st_rdev);
            if (major_len < mx_intlen(major))
                major_len = mx_intlen(major);

            if (minor <= 255) {
                if (minor_len < mx_intlen(minor))
                    minor_len = mx_intlen(minor);

            }            
        }

        if (forth_len < mx_intlen(sb.st_size))
            forth_len = mx_intlen(sb.st_size);

        blocks += sb.st_blocks;
        mx_strdel(&path_name_1);
        mx_strdel(&path_name_2);     
        }

        minor_major_len = 3 + major_len + minor_len;

        mx_printstr("total ");
        mx_printint(blocks);
        mx_printstr("\n");
        
 
        



 

    for (int i = 0; sort_arr[i] != NULL; i++) {

        path_name_1 = mx_strjoin(dir_name, "/");
        path_name_2 = mx_strjoin(path_name_1, sort_arr[i]);

        lstat(path_name_2, &sb);

        if ((sb.st_mode & S_IFIFO) == S_IFIFO) {
            my_acl_line[0] = 'p';
        }

        if ((sb.st_mode & S_IFCHR) == S_IFCHR) {
            my_acl_line[0] = 'c';
            dev_flag = 1;
        }
        if ((sb.st_mode & S_IFDIR) == S_IFDIR) {
            my_acl_line[0] = 'd';
            dev_flag = 0;
        }
        if ((sb.st_mode & S_IFBLK) == S_IFBLK) {
            my_acl_line[0] = 'b';
            dev_flag = 1;
        }
        if ((sb.st_mode & S_IFREG) == S_IFREG) {
            my_acl_line[0] = '-';
        }
        if ((sb.st_mode & S_IFLNK) == S_IFLNK) {
            my_acl_line[0] = 'l';
            l_flag = 1;
        }
        // if ((sb.st_mode & S_IFSOCK) == S_IFSOCK) {
        // my_acl_line[0] = 'l';
        // printf("l-");
        // }

        if ((sb.st_mode & S_IRUSR) == S_IRUSR) {
            my_acl_line[1] = 'r';
        }
        if ((sb.st_mode & S_IWUSR) == S_IWUSR) {
            my_acl_line[2] = 'w';
        }
        if ((sb.st_mode & S_IXUSR) == S_IXUSR) {
            my_acl_line[3] = 'x';
        }
        if ((sb.st_mode & S_ISUID) == S_ISUID) {
            my_acl_line[3] = 's';
        }

        if ((sb.st_mode & S_IRGRP) == S_IRGRP) {
            my_acl_line[4] = 'r';
        }
        if ((sb.st_mode & S_IWGRP) == S_IWGRP) {
            my_acl_line[5] = 'w';
        }
        if ((sb.st_mode & S_IXGRP) == S_IXGRP) {
            my_acl_line[6] = 'x';
        }
        if ((sb.st_mode & S_ISGID) == S_ISGID) {
            my_acl_line[6] = 's';
        }

        if ((sb.st_mode & S_IROTH) == S_IROTH) {
            my_acl_line[7] = 'r';
        }
        if ((sb.st_mode & S_IWOTH) == S_IWOTH) {
            my_acl_line[8] = 'w';
        }
        if ((sb.st_mode & S_IXOTH) == S_IXOTH) {
            my_acl_line[9] = 'x';
        }
        if ((sb.st_mode & S_ISVTX) == S_ISVTX) {
            my_acl_line[9] = 't';
        }

        my_acl = acl_get_file(sort_arr[i], ACL_TYPE_EXTENDED);
        text_acl = acl_to_text(my_acl, &len);
        buflen = listxattr(sort_arr[i], NULL, 0, XATTR_NOFOLLOW);

        //my_acl_line[10] = '';

        if (text_acl != NULL)
            my_acl_line[10] = '+';
        if (buflen > 0)
            my_acl_line[10] = '@';

        if (l_flag == 1) {
            readlink(sort_arr[i], buf_link, sizeof(buf_link));
        }

        if (dev_flag == 1) {
            minor = minor(sb.st_rdev);
            major = major(sb.st_rdev);
        }

        if (acl_free(text_acl) == -1) {

            perror("acl_free()");
        }
        free(my_acl);

        if (malloc_size(text_acl))
            free(text_acl);

        mx_printstr(my_acl_line);
        mx_printstr(" ");
        for (int j = 0; j < first_len - mx_intlen(sb.st_nlink); j++) {
            mx_printstr(" ");           
        }
        mx_printint(sb.st_nlink);
        mx_printstr(" ");
        user_info = getpwuid(sb.st_uid);

        mx_printstr(user_info->pw_name);
        mx_printstr("  ");
        for (int j = 0; j < second_len - mx_strlen(user_info->pw_name); j++)
            mx_printstr(" ");
        

        gruop_info = getgrgid(sb.st_gid);

        if (gruop_info != NULL) {
            mx_printstr(gruop_info->gr_name);
            for (int j = 0; j < third_len - mx_strlen(gruop_info->gr_name); j++) 
                mx_printstr(" ");
        }
        else {
            mx_printint(user_info->pw_gid);
            for (int j = 0; j < third_len - mx_intlen(user_info->pw_gid); j++) 
                mx_printstr(" ");
        }
        mx_printstr("  ");



        if (dev_flag == 1 && l_flag != 1) {
            if (forth_len > minor_major_len) {
                for (int j = 0; j < forth_len - minor_major_len; j++) 
                mx_printstr(" ");
            }
            else 
                mx_printstr(" ");
            for (int j = 0; j < major_len - mx_intlen(major); j++)
                mx_printstr(" ");

            mx_printint(major);
            mx_printstr(",");
            mx_printstr(" ");

            if (minor > 255) {
                nbr = mx_nbr_to_hex(minor);
                int n = 8 - mx_strlen(nbr);
                need_nul = mx_strndup("0x00000000", n + 2);
                binar = mx_strjoin(need_nul, nbr);
                mx_printstr(binar);
            } 
            else {
                for (int j = 0; j < minor_len - mx_intlen(minor); j++)
                     mx_printstr(" ");
                mx_printint(minor);
            }
            mx_strdel(&nbr);
            mx_strdel(&need_nul);
            mx_strdel(&binar);
            dev_flag = 0;
        } 
        else {
            if (flag_device == 1) {
                if (forth_len < minor_major_len){
                    for (int j = 0; j < minor_major_len - mx_intlen(sb.st_size); j++) 
                        mx_printstr(" ");                   
                }                 

            }
            else {
                for (int j = 0; j < forth_len - mx_intlen(sb.st_size); j++) 
                    mx_printstr(" ");            
            }
            mx_printint(sb.st_size);
        }
        mx_printstr(" ");
        time = ctime(&sb.st_mtime);

        // printf("%s   ", time);

        time_arr = mx_strsplit(time, ' ');

        hour = mx_str_copy(time_arr[3]);
        hour_arr = mx_strsplit(hour, ':');
        mx_printstr(time_arr[1]);
        mx_printstr(" ");
        mx_printstr(time_arr[2]);
        mx_printstr(" ");
        mx_printstr(hour_arr[0]);
        mx_printstr(":");
        mx_printstr(hour_arr[1]);
        mx_printstr(" ");
        mx_printstr(sort_arr[i]);

        // printf("%s  ", time_arr[1]);
        // printf("%s   ", time_arr[2]);

        // printf("%s", hour_arr[0]);
        // printf(":");
        // printf("%s   ", hour_arr[1]);

        // printf("%s ", sort_arr[i]);

        mx_del_strarr(&time_arr);
        mx_del_strarr(&hour_arr);
        mx_strdel(&hour);
        mx_strdel(&path_name_1);
        mx_strdel(&path_name_2);

        if (l_flag == 1) {
            mx_printstr("-> %s");
            mx_printstr(buf_link);
            l_flag = 0;
        }

        mx_printchar('\n');

        my_acl_line[0] = '-';
        my_acl_line[1] = '-';
        my_acl_line[2] = '-';
        my_acl_line[3] = '-';
        my_acl_line[4] = '-';
        my_acl_line[5] = '-';
        my_acl_line[6] = '-';
        my_acl_line[7] = '-';
        my_acl_line[8] = '-';
        my_acl_line[9] = '-';
        my_acl_line[10] = ' ';
    }
}

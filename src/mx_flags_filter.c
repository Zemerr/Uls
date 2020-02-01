#include "../inc/header.h"

static void sort_flags_two(char c, t_flags *flag) {
    switch(c) {
        case('f'):
            if ((*flag).d == 0) {
                (*flag).f = 1;
                (*flag).a = 1;
                (*flag).S = 0;
                (*flag).t = 0;
            }
            break;
        case('o'):
            (*flag).o = 1;
            (*flag).l = 1;
            break;
        case('T'):
            (*flag).T = 1;
            break;
        case('r'):
            (*flag).r = 1;
            break;
    }
}

static void sort_flags_one(char c, t_flags *flag) {
    switch(c)
    {
        case('S'):
            (*flag).S = 1;
            (*flag).t = 0;
            (*flag).u = 0;
            break;
        case('t'):
            if ((*flag).S == 0)
                (*flag).t = 1;
            break;
        case('h'):
            (*flag).h = 1;
            break;
        case('u'):
            if ((*flag).S == 0)
                (*flag).u = 1;
            break;
    }
}

static void data_flags(char c, t_flags *flag) {
    switch(c)
    {
        case('a'):
            if ((*flag).d == 0) {
                (*flag).a = 1;
                (*flag).A = 0;
            }
            break;
        case('A'):
            if ((*flag).a == 0 && (*flag).d == 0)
                (*flag).A = 1;
            break;
        case('d'):
            (*flag).d = 1;
            (*flag).a = 0;
            (*flag).A = 0;
            break;
    }
}

t_flags *mx_flags_filter(char *str) {
    t_flags *flag = (t_flags *)malloc(sizeof(t_flags));

    mx_memset(flag, 0, sizeof(t_flags));
        for (int i = 0; str[i] != '\0'; i++) {
            data_flags(str[i], flag);
            sort_flags_one(str[i], flag);
            sort_flags_two(str[i], flag);
            mx_output_flags(str[i], flag);
        }
        if (isatty(1) == 0) {
            (*flag).G = 0;
                if ((*flag).C == 0 && (*flag).m == 0)
                    (*flag).one = 1;
        }
        mx_strdel(&str);
        return flag;
}

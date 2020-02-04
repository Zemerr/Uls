#include "header.h"

static void second_part(char c, t_flags *flag) {
    switch(c) {
        case('g'):
            (*flag).g = 1;
            (*flag).l = 1;
            break;
        case('p'):
            (*flag).p = 1;
            (*flag).F = 0;
            break;
        case('F'):
            (*flag).F = 1;
            (*flag).p = 0;
            break;
        case('-'):
            break;
    }
}

static void first_part(char c, t_flags *flag) {
    switch(c) {
        case('C'):
            (*flag).C = 1;
            (*flag).one = 0;
            (*flag).l = 0;
            break;
        case('1'):
            (*flag).one = 1;
            (*flag).C = 0;
            (*flag).m = 0;
            (*flag).l = 0;
            break;
        case('m'):
            (*flag).m = 1;
            (*flag).one = 0;
            (*flag).C = 0;
            (*flag).l = 0;
            break;
    }
}

void mx_output_flags(char c, t_flags *flag) {
    first_part(c, flag);
    second_part(c, flag);
    switch(c) {
        case('l'):
            (*flag).l = 1;
            (*flag).m = 0;
            break;
        case('G'):
            (*flag).G = 1;
            break;
        case('R'):
            (*flag).R = 1;
            break;
    }
}

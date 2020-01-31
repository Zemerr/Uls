#include "../inc/header.h"


t_flags *mx_flags_filter(char *str) {
	t_flags *flag = (t_flags *)malloc(sizeof(t_flags));

	mx_memset(flag, 0, sizeof(t_flags));
	for (int i = 0; str[i] != '\0'; i++) {
		switch (str[i])
		{
			case('A'):
				if ((*flag).a == 0) {
					(*flag).A = 1;
				}
				break;
			case('a'):
				(*flag).a = 1;
				(*flag).A = 0;
				break;
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
			case('S'):
				(*flag).S = 1;
				(*flag).t = 0;
				(*flag).u = 0;
				break;
			case('t'):
				if ((*flag).S == 0) {
					(*flag).t = 1;
				}
				break;
            case('h'):
				(*flag).h = 1;
				break;
			case('u'):
				if ((*flag).S == 0) {
					(*flag).u = 1;
				}
				break;
			case('r'):
				(*flag).r = 1;
				break;
			case('C'):
				(*flag).C = 1;
				(*flag).one = 0;
				(*flag).l = 0;
				break;
			case('1'):
				(*flag).one = 1;
				(*flag).C = 0;
				(*flag).m = 0;
				break;
			case('m'):
				(*flag).m = 1;
				(*flag).one = 0;
				(*flag).C = 0;
				(*flag).l = 0;
				break;
            case('g'):
				(*flag).g = 1;
                (*flag).l = 1;
				break;
            case('o'):
				(*flag).o = 1;
                (*flag).l = 1;
				break;
            case('T'):
				(*flag).T = 1;
				break;
            case('-'):
				break;
		}
	}
	if (isatty(1) == 0) {
		(*flag).G = 0;
		if ((*flag).C == 0 && (*flag).m == 0)
			(*flag).one = 1;
	}
	mx_strdel(&str);
	return flag;
}

#include "../inc/header.h"

static char *flags_fill_in(char **argv, int count) {
	char *flags = NULL;
	int o = 0;

	if (count == -1) {
		return NULL;
	}
	flags = (char *)malloc(sizeof(char) * count + 1);
		for (int j = 1; argv[j] != NULL; j++) {
			if (argv[j][0] == '-') {
				for (int i = 1; argv[j][i] != '\0'; i++, o++) {
					flags[o] = argv[j][i];
				}
			}
		}
		flags[o] = '\0';

		return flags;
}

t_flags *mx_flags_filter(char **argv, int count) {
	char *str = flags_fill_in(argv, count);
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
				break;
			case('t'):
				if ((*flag).S == 0)
					(*flag).t = 1;
				break;
		}
	}
	mx_strdel(&str);
	return flag;
}

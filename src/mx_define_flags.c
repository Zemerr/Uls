#include "../inc/header.h"

//so basically, while executing, ls has 3 stages:
//		1 -> getting the data needed;
//		2 -> sorting, if necessary;
//		3 -> output;
//that's how we will check based on the flages we get
//WHAT & in which ORDER & HOW to work; 

static int determine_size(char **arr) {
	int size = 0;

	while (arr[size]) {
		size++;
	}
	return size;
}

static char **data(t_flags *flag, char *file_name) {
	//we get a directory name
	//&& should return an array of objects in it;
	char trig;
	char **obj_arr = NULL;
		if ((*flag).a == 1) {
			trig = 'a';
		}
		if ((*flag).A == 1) {
			trig = 'A';
		}
	obj_arr = mx_files_in_dir(file_name, trig);
	return obj_arr;
}

//if you print : ls -lC you get standard output (ls without flags);
//if you print : ls -Cl you get output for 'l' flag;
//same works with flag '1';

void mx_define_flags(char *file_name, t_flags *flags) {
	char **obj_arr = data(flags, file_name);
	int size = determine_size(obj_arr);
	printf("%d\n", size);
	mx_print_cols(obj_arr, size);
}

//if flag 'G' -> use spaces while print;
//else ->tabs;

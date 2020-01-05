#include "../inc/header.h"

int mx_flag_l(char **sort_arr) {	
	struct stat sb;
	char my_acl[] = "-----------"; 
	struct passwd user_info;

	for(int i = 0; sort_arr[i] != NULL; i++) {
		lstat(sort_arr[i], &sb);

		if ((sb.st_mode & S_IFMT) == S_IFDIR) {
			my_acl[0] = 'd'; 
		}
		if ((sb.st_mode & S_IFMT) == S_IFBLK) {
			my_acl[0] = 'b'; 
		}
		if ((sb.st_mode & S_IFMT) == S_ISCHR) {
			my_acl[0] = 'c'; 
		}
		if ((sb.st_mode & S_IFMT) == S_ISFIFO) {
			my_acl[0] = 'p'; 
		}
		if ((sb.st_mode & S_IFMT) == S_IFLNK) {
		my_acl[0] = 'l'; 
		}


		if ((sb.st_mode & S_IRWXU) == S_IRUSR) {
			my_acl[1] = 'r'; 
		}
		if ((sb.st_mode & S_IRWXU) == S_IWUSR) {
			my_acl[2] = 'w'; 
		}
		if ((sb.st_mode & S_IRWXU) == S_IXUSR) {
			my_acl[3] = 'x'; 
		}
		if ((sb.st_mode & S_ISUID) == S_ISUID) {
			my_acl[3] = 's'; 
		}


		if ((sb.st_mode & S_IRWXG) == S_IRGRP) {
			my_acl[4] = 'r'; 
		}
		if ((sb.st_mode & S_IRWXG) == S_IWGRP) {
			my_acl[5] = 'w'; 
		}
		if ((sb.st_mode & S_IRWXG) == S_IXGRP) {
			my_acl[6] = 'x'; 
		}
		if ((sb.st_mode & S_ISGID) == S_ISGID) {
			my_acl[6] = 's'; 
		}


		if ((sb.st_mode & S_IRWXO) == S_IROTH) {
			my_acl[7] = 'r'; 
		}
		if ((sb.st_mode & S_IRWXO) == S_IWOTH) {
			my_acl[8] = 'w'; 
		}
		if ((sb.st_mode & S_IRWXO) == S_IXOTH) {
			my_acl[9] = 'x'; 
		}
		if ((sb.st_mode & S_ISVTX) == S_ISVTX) {
			my_acl[9] = 't'; 
		}



		printf("%s", my_acl);
		printf("%hu\n", buff.st_nlink);







	}
}


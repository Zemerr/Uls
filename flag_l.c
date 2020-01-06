#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 

void mx_flag_l(char **sort_arr) {	
	struct stat sb;


	char my_acl_line[] = "-----------"; 


	//char my_acl_line[] = "-----------"; 

	//struct passwd user_info;
	acl_t my_acl;
	char  *text_acl;
    ssize_t len;
    ssize_t buflen;

	for(int i = 0; sort_arr[i] != NULL; i++) {

		lstat(sort_arr[i], &sb);
		


		if ((sb.st_mode & S_IFIFO) == S_IFIFO) {
			my_acl_line[0] = 'p';
			 
		}

		if ((sb.st_mode & S_IFCHR) == S_IFCHR) {
			my_acl_line[0] = 'c';
			
		}
		if ((sb.st_mode & S_IFDIR) == S_IFDIR) {
			my_acl_line[0] = 'd'; 
			
		}
		if ((sb.st_mode & S_IFBLK) == S_IFBLK) {
			my_acl_line[0] = 'b'; 
					
		}
		if ((sb.st_mode & S_IFREG) == S_IFREG) {
			my_acl_line[0] = '-'; 
			
		}
		if ((sb.st_mode & S_IFLNK) == S_IFLNK) {
		my_acl_line[0] = 'l';
		 
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

		my_acl = acl_get_file (sort_arr[i], ACL_TYPE_EXTENDED);
  		text_acl = acl_to_text (my_acl, &len);
  		buflen = listxattr(sort_arr[i], NULL, 0, XATTR_SHOWCOMPRESSION);



  		if (text_acl != NULL)
  			my_acl_line[10] = '+';
  		else if (buflen > 0)
  			my_acl_line[10] = '@';
  		else 
  			my_acl_line[10] = '\0';

 	 


		if (acl_free (text_acl) == -1)
		{
		perror ("acl_free()");
		
		}

		printf("%s ====================== %s\n\n", sort_arr[i], my_acl_line);
	//	printf("%hu\n", buff.st_nlink);

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
		my_acl_line[10] = '-';
	



		



	}
}


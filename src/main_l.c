#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <stdlib.h>
#include <pwd.h>
#include "../inc/header.h"





int main() {

 // acl_t my_acl;
  // char  *text_acl;
  // ssize_t len;

   
  char *path = "./";

  DIR *dir;
  struct dirent *entry;
  //struct stat buff;
  int count = 0;

  dir = opendir(path);
  entry = readdir(dir);

    if (dir != NULL) {
   entry = readdir(dir);
    while (entry) {
      //if ((*entry).d_name[0] != '.') {
        count++;
     // }
      entry = readdir(dir);
    }
    closedir(dir);
  }


  char **files = (char **)malloc(sizeof(char *) * count+1);
  int q = 0;
    
    
  // files[q] = NULL;

    dir = opendir(path);
  entry = readdir(dir);

  while(entry != NULL) {
 //   printf("%s       ", entry->d_name);

    files[q] = mx_strjoin(path, entry->d_name);
      q++;




  //  printf ("\n===============\n");
  
    //lstat(entry->d_name, &buff);
   //  my_acl = acl_get_file (entry->d_name, ACL_TYPE_ACCESS);
  	// text_acl = acl_to_text (my_acl, &len);
 	 // printf ("Updated ACL: %s\n", text_acl);



    // printf("Size of the file is: %lld\n", buff.st_size);
    // printf("режим доступа: %hu\n", buff.st_mode);


    // printf("inode: %llu\n", buff.st_ino);
    // printf("количество жестких ссылок: %hu\n", buff.st_nlink);
    // printf(" время последнего доступа: %ld\n", buff.st_atime);
    // printf("время последней модификации: %ld\n", buff.st_mtime);
    // printf("время последнего изменения: %ld\n", buff.st_ctime);


    entry = readdir(dir);
 //   printf ("\n===============\n");

  


    
  }

 files[q] = NULL;


  


  closedir(dir);
  mx_flag_l(files);
  system("leaks -q uls");

  

  // if (acl_free (text_acl) == -1)
  // {
  //   perror ("acl_free()");
  //   return 0;
  // }


//     int n = 11;
// printf("%d", mx_intlen(n));



  return 0;
}

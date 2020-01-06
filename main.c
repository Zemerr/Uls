#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <stdlib.h>

void mx_flag_l(char **sort_arr);

int mx_strlen(const char *s) {
    int size = 0;

    for (int i = 0; s[i] != '\0'; i ++) {
        size = size + 1;
    }
    return size;
}


char *mx_str_copy(char *src) {
  char *copy = NULL;
  int size = mx_strlen(src);
  int i = 0;

  copy = (char *)malloc(sizeof(char) * size + 1);
    for (i = 0; i < size; i++) {
      copy[i] = src[i];
    }
    copy[i] = '\0';
    return copy;
}


int main() {

 // acl_t my_acl;
  // char  *text_acl;
  // ssize_t len;

  DIR *dir;
  struct dirent *entry;
  //struct stat buff;
  int count = 0;

  dir = opendir(".");
  entry = readdir(dir);

    if (dir != NULL) {
   entry = readdir(dir);
    while (entry) {
      if ((*entry).d_name[0] != '.') {
        count++;
      }
      entry = readdir(dir);
    }
    closedir(dir);
  }


  char **files = (char **)malloc(sizeof(char *) * count+1);
  int q = 0;
    
    
   files[q] = NULL;

    dir = opendir(".");
  entry = readdir(dir);

  while(entry != NULL) {
 //   printf("%s       ", entry->d_name);

    files[q] = mx_str_copy(entry->d_name);
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

  

  // if (acl_free (text_acl) == -1)
  // {
  //   perror ("acl_free()");
  //   return 0;
  // }






  return 0;
}

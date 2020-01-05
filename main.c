#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/acl.h>

int main() {

 // acl_t my_acl;
  // char  *text_acl;
  // ssize_t len;
  DIR *dir;
  struct dirent *entry;
  struct stat buff;

  dir = opendir(".");
  entry = readdir(dir);

  while(entry != NULL) {
    printf("%s       ", entry->d_name);
    printf ("\n===============\n");
  
    lstat(entry->d_name, &buff);
   //  my_acl = acl_get_file (entry->d_name, ACL_TYPE_ACCESS);
  	// text_acl = acl_to_text (my_acl, &len);
 	 // printf ("Updated ACL: %s\n", text_acl);



    printf("Size of the file is: %lld\n", buff.st_size);
    printf("режим доступа: %hu\n", buff.st_mode);


    printf("inode: %llu\n", buff.st_ino);
    printf("количество жестких ссылок: %hu\n", buff.st_nlink);
    printf(" время последнего доступа: %ld\n", buff.st_atime);
    printf("время последней модификации: %ld\n", buff.st_mtime);
    printf("время последнего изменения: %ld\n", buff.st_ctime);


    entry = readdir(dir);
    printf ("\n===============\n");

    if ((buff.st_mode & S_IFMT) == S_IFDIR) {
    	printf("dir\n" );
    }


    
  }
  


  closedir(dir);

  

  // if (acl_free (text_acl) == -1)
  // {
  //   perror ("acl_free()");
  //   return 0;
  // }






  return 0;
}

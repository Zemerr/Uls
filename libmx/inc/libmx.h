#ifndef _LIBMIX_H_
#define _LIBMIX_H_

#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <fcntl.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}		t_list;


int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_itoa(int number);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
char **mx_strsplit(const char *s, char c);
char *mx_file_to_str(const char *file);
int mx_count_words(const char *str, char c);
int mx_bubble_sort(char **arr);
void mx_printstr(const char *s);
char *mx_strjoin( char *s1,  char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_nbr_to_hex(unsigned long nbr);
char *mx_strndup(const char *s1, size_t n);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_printint(int n);
void mx_printchar(char c);
int mx_intlen(signed long long num);
char *mx_strjoin_one( char *s1,  char *s2);
char *mx_strjoin_two( char *s1,  char *s2);
void mx_strdel_three(char **str1, char **str2, char **str3);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
void *mx_memset(void *b, int c, size_t len);
void mx_printstr_err(const char *s);

#endif

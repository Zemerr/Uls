#include "../inc/header.h"

char *str_copy(char *src) {
	char *copy = NULL;
	int size = mx_strlen(src);

	copy = (char *)malloc(sizeof(char) * size);
		for (int i = 0; src[i]; i++) {
			copy[i] = src[i];
		}
		return copy;
}

#include "../inc/libmx.h"

static char **arr_creation(const char *s, char c, int quantity) {
    int j = 0;
    int i = 0;
    int k = 0;
    char **arr = (char **)malloc(sizeof(char *) * quantity + 1);

    while(j < quantity && s[i] != '\0') {
        while (s[i] == c) {
            i++;
        }
        while (s[i] != c) {
            k++;
            i++;
        }
        arr[j] = (char *)malloc(sizeof(char ) * k + 1);
        k = 0;
        j++;
    }
    arr[j] = NULL;
    return arr;
} 

static void fill_arr(char **arr, int quantity, const char *s, char c) {
    int i = 0;
    int k = 0;

    for (int j = 0; j < quantity && s[i] != '\0'; j++) {
        while (s[i] == c) {
            i++;
        }
        while (s[i] != c) {
            arr[j][k] = s[i];
            k++;
            i++;
        }
        arr[j][k] = '\0';
        k = 0;
    }
}

char **mx_strsplit(const char *s, char c) {
    int quantity = mx_count_words(s, c);
    char **arr = NULL;

	if (quantity == -1) {
		return NULL;
	}
    arr = arr_creation(s, c, quantity);
    fill_arr(arr, quantity, s, c);
	return arr;
}

#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                char *fake = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = fake;
                count = count + 1;
             }
         }
    }
return count;
}

#include "libmx.h"

int mx_bubble_sort(char **arr) {
    int count = 0;

    for (int i = 0; arr[i]; i++) {
        for (int j = 0; arr[j-1]; j++) {
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

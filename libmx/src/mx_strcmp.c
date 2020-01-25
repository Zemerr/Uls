#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int r;

    if (s1 != NULL && s2 != NULL) {
        for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
            if (s1[i] > s2[i]) {
                r = s1[i] - s2[i];
                return r;
            }
            else if (s1[i] < s2[i]) {
                r = s2[i] - s1[i];
                return -r;
            }
        }
    }
    return 0;
}

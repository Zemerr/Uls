#include "header.h"

void mx_del_timearr(char ***arr) {
    for (int i = 0; (*arr)[i]; i++) {
        mx_strdel(&(*arr)[i]);
    }
}

#include "header.h"

void mx_print_error_file(char *error_file) {
    mx_printstr_err("uls: ");
    perror(error_file);
}

#include "../inc/header.h"

static int files_count(int argc, char **argv) {
    int count = 0;

    if (argc == 0)
        return 0;
    for (int i = 1; argv[i]; i++) {
        if (count > 0 && argv[i][0] == '-')
            return -1;
        if (argv[i][0] != '-')
            count++;
    }
    return count;
}

static int flags_count(char **argv) {
    int count = 0;

    for (int j = 1; argv[j] != NULL; j++) {
        if (argv[j][0] == '-') {
            for (int i = 1; argv[j][i] != '\0'; i++) {
                    if (argv[j][i] == '-')
                        return -1;
                    count++;
            }
        }
    }
    return count;
}

static char **files_fill_in(int argc, char **argv) {
    char **files = (char **)malloc(sizeof(char *) * argc);
    int q = 0;
    int j = 1;

    for ( ; argv[j]; j++) {
        if (argv[j][0] != '-')
            files[q] = mx_str_copy(argv[j]);
        q++;
    }
    files[q] = NULL;
    return files;
}

int main(int argc, char **argv) {
    int filec = files_count(argc, argv);
    char **files = NULL;
    int flagc = flags_count(argv);
    t_flags *flags = mx_flags_filter(argv, flagc);

    if (flagc == -1 || filec == -1) {
            write(2, "usage: uls [-lGRAa] [file ...]\n",
                mx_strlen("usage: uls [-lGRAa] [file ...]\n"));
                return 0;
    }
    if (filec == 0) {
        mx_define_flags(".", flags);
    }
    if (filec != 0) {
        files = files_fill_in(argc, (argv));
        mx_file_specified(files, flags, ".");
    }
   // system("leaks uls");
}

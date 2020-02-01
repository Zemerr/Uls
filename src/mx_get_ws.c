#include "../inc/header.h"

int mx_get_ws() {
    struct winsize ws;
    int fd;
    int cols = 0;

    fd = open("/dev/tty", O_RDWR);
    ioctl(fd, TIOCGWINSZ, &ws);
    close(fd);
    cols = ws.ws_col;
    return cols;
}

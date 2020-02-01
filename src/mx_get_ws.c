#include "header.h"

int mx_get_ws() {
	struct winsize ws;
	int fd;
	int cols = 0;

	fd = open("/dev/tty", O_RDWR);
		if (fd < 0)
			err(1, "/dev/tty");
		if (ioctl(fd, TIOCGWINSZ, &ws) < 0)
			err(1, "/dev/tty");
		close(fd);
		cols = ws.ws_col;
		return cols;
}

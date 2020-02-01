NAME = libmx.a

HEADERS = libmx.h \

FILES = mx_file_to_str \
	mx_strlen \
	mx_strsplit \
	mx_strnew \
	mx_strdel \
	mx_strcmp \
	mx_itoa \
	mx_del_strarr \
	mx_count_words \
	mx_bubble_sort \
	mx_printstr \
	mx_strjoin \
	mx_strcat \
	mx_nbr_to_hex \
	mx_strndup \
	mx_printint \
	mx_printchar \
	mx_strjoin_one \
	mx_strjoin_two \
	mx_strdel_three \
	mx_del_two_arr \
	mx_strdup \
	mx_strcpy \
	mx_strncpy \
	mx_memset \
	mx_printstr_err \

INC_H = $(addprefix "inc/", $(HEADERS))

ROOT_C = $(addsuffix ".c", $(FILES))

SRC_C = $(addprefix "src/", $(ROOT_C))

ROOT_O = $(addsuffix ".o", $(FILES))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@cp $(SRC_C) .
	@cp $(INC_H) .
	@clang $(CFLAGS) -c $(ROOT_C)
	@mkdir -p obj
	@cp $(ROOT_O) obj/
	@ar -rc $(NAME) $(ROOT_O)
	@rm -rf $(ROOT_O)

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(ROOT_C)
	@rm -rf $(HEADERS)
	@rm -rf obj

reinstall: uninstall install

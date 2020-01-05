NAME = libmx.a

DIROBJ = obj

SRC = src/mx_del_strarr.c \
	src/mx_file_to_str.c \
	src/mx_itoa.c \
	src/mx_strcmp.c \
	src/mx_strdel.c \
	src/mx_strlen.c \
	src/mx_strnew.c \
	src/mx_strsplit.c \
	src/mx_count_words.c \
	src/mx_bubble_sort.c \
	src/mx_printstr.c \

OUT = mx_file_to_str.o \
	mx_strlen.o \
	mx_strsplit.o \
	mx_strnew.o \
	mx_strdel.o \
	mx_strcmp.o \
	mx_itoa.o \
	mx_del_strarr.o \
	mx_count_words.o \
	mx_bubble_sort.o \
	mx_printstr.o \

CLANG = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = inc/libmx.h

all: install

install:
	@mkdir -p $(DIROBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@ar -rc $(NAME) $(OUT)
	@mv $(OUT) $(DIROBJ)

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(DIROBJ)
	@rm -rf $(OUT)

reinstall: uninstall install


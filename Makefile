NAME = uls

DIROBJ = obj

SRC = src/main.c \
	src/mx_files_in_dir.c \
	src/mx_get_ws.c \
	src/mx_print_cols.c \
	src/mx_file_specified.c \
	src/mx_files_quantity.c \
	src/mx_dir_arr.c \
	src/mx_file_arr.c \
	src/mx_file_mode_check.c \
	src/mx_str_copy.c \
	src/mx_define_flags.c \
	src/mx_flag_l.c \
	src/mx_intlen.c \
	src/mx_colour_out.c \
	src/mx_flag_g.c \
	src/mx_recursion_call.c \
	src/mx_flags_filter.c \

OUT = main.o \
	mx_files_in_dir.o \
	mx_get_ws.o \
	mx_print_cols.o \
	mx_file_specified.o \
	mx_files_quantity.o \
	mx_dir_arr.o \
	mx_file_arr.o \
	mx_file_mode_check.o \
	mx_str_copy.o \
	mx_define_flags.o \
	mx_flag_l.o \
	mx_intlen.o \
	mx_colour_out.o \
	mx_flag_g.o \
	mx_recursion_call.o \
	mx_flags_filter.o \

CLANG = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = inc/header.h

LIBMX = libmx/libmx.a

all: install

install:
	@mkdir -p $(DIROBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@make all -C libmx
	@clang $(CLANG) $(SRC) $(LIBMX) -o $(NAME) -I $(INC)

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -C libmx

clean:
	@rm -rf $(DIROBJ)
	@rm -rf $(OUT)
	@make clean -C libmx

reinstall: uninstall install

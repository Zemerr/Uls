NAME = uls

ROOT_A = libmx.a \

LIB_A = ./libmx/libmx.a \

HEADERS = header.h \

FILES = main \
	mx_files_in_dir \
	mx_get_ws \
	mx_print_cols \
	mx_file_specified \
	mx_files_quantity \
	mx_dir_arr \
	mx_file_arr \
	mx_file_mode_check \
	mx_str_copy \
	mx_define_flags \
	mx_flag_l \
	mx_intlen \
	mx_colour_out \
	mx_for_flagl_one \
	mx_for_flagl_two \
	mx_acl_line \
	mx_print_size_mm \
	mx_print_name_acl \
	mx_print_link_update \
	mx_flag_g \
	mx_recursion_call \
	mx_flags_filter \
	mx_find_path \
	mx_flag_sort \
	mx_upgraded_sort \
	mx_simple_out \
	mx_error_check \
	mx_flag_file_valid \
	mx_print_time \
	mx_for_flag_h \
	mx_flag_d \
	mx_flag_p \
	mx_output_flags \

INC_H = $(addprefix "inc/", $(HEADERS))

ROOT_C = $(addsuffix ".c", $(FILES))

SRC_C = $(addprefix "src/", $(ROOT_C))

ROOT_O = $(addsuffix ".o", $(FILES))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C libmx install
	@cp $(SRC_C) .
	@cp $(INC_H) .
	@cp $(LIB_A) .
	@clang $(CFLAGS) -c $(ROOT_C)
	@clang $(CFLAGS) $(ROOT_O) $(ROOT_A) -o $(NAME)
	@mkdir -p obj
	@cp $(ROOT_O) obj/
	@rm -rf $(ROOT_O)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)

clean:
	@make -C libmx clean
	@rm -rf $(ROOT_C)
	@rm -rf $(ROOT_A)
	@rm -rf $(HEADERS)
	@rm -rf obj

reinstall: uninstall install

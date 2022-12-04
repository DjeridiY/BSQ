##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SOURCE =	src/

SRC =	$(SOURCE)main.c	\
		$(SOURCE)nbr_of_col.c	\
		$(SOURCE)nbr_of_lines.c	\
		$(SOURCE)tools/string_to_int.c	\
		$(SOURCE)/tools/my_str_to_int_array.c	\
		$(SOURCE)/resolve_map.c	\
		$(SOURCE)/replace_coord.c	\
		$(SOURCE)/search_coord.c	\
		$(SOURCE)/tools/my_str_to_char_array.c	\
		$(SOURCE)/error_case_av.c	\
		$(SOURCE)/get_size.c	\
		$(SOURCE)/condition_reset.c	\
		$(SOURCE)/get_patern.c	\
		$(SOURCE)/generate_map_char_int.c	\
		$(SOURCE)file_to_tab.c

BINARY	=	bsq

all:
	make -C lib/my/
	gcc -o $(BINARY) $(SRC) -L lib/my/ -lmy -g3

clean :
	make -C lib/my/ clean

fclean: clean
	make -C lib/my/ fclean

re:     fclean all

.PHONY: all clean fclean re

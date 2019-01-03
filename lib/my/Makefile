##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Basic makefile to compile 'my' library
##

SRC		= 	get_color.c 						\
			my_compute_power_rec.c 				\
			my_compute_square_root.c 			\
			my_find_prime_sup.c 				\
			my_getnbr.c 						\
			my_is_prime.c 						\
			my_isalphanumeric.c 				\
			my_isletter.c 						\
			my_isneg.c 							\
			my_isnumber.c 						\
			my_put_nbr.c 						\
			my_putnbr_base.c 					\
			my_putstr.c 						\
			my_revstr.c 						\
			my_putchar.c 						\
			my_showmem.c 						\
			my_showstr.c 						\
			my_sort_int_array.c 				\
			my_str_isalpha.c 					\
			my_str_islower.c 					\
			my_str_isnum.c 						\
			my_str_isprintable.c 				\
			my_str_isupper.c 					\
			my_str_to_word_array.c 				\
			my_strcapitalize.c 					\
			my_strcat.c 						\
			my_strcmp.c 						\
			my_strcpy.c 						\
			my_strdup.c 						\
			my_strlen.c 						\
			my_strlowcase.c 					\
			my_strncat.c 						\
			my_strncmp.c 						\
			my_strncpy.c 						\
			my_strstr.c 						\
			my_strupcase.c 						\
			my_swap.c 							\
			my_strtol.c 						\
			my_strdupcat.c 						\
			./my_printf/src/my_printf.c 						\
			./my_printf/src/type/signed_int/small_len.c 		\
			./my_printf/src/type/signed_int/big_len.c 			\
			./my_printf/src/type/unsigned_int/small_len.c 		\
			./my_printf/src/type/unsigned_int/big_len.c 		\
			./my_printf/src/type/char.c 						\
			./my_printf/src/type/string.c 						\
			./my_printf/src/type/pointer.c 						\
			./my_printf/src/handle_args/parse_redirect.c 		\
			./my_printf/src/handle_args/extra_flags.c 			\
			./my_printf/src/handle_args/precision.c 			\
			./my_printf/src/utils/utils.c 						\
			./my_printf/src/utils/print/print.c 				\
			./my_printf/src/utils/print/print_int.c 			\
			./my_printf/src/utils/print/print_uint.c 			\
			./my_printf/src/utils/print/print_string.c 			\
			./my_printf/src/utils/flags.c 						\
			./my_printf/src/utils/getid.c 						\

OBJ 	= 	$(SRC:.c=.o)
NAME_LIB 	= 	libmy.a
NAME_INCLUDE 	=	my.h

CFLAGS			=	-I ./

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ) my
	rm ./my_printf/src/main.c -f
	rm ./my_printf/src/main_test.c -f
	ar rc $(NAME_LIB) $(OBJ)

my:
	cp $(NAME_INCLUDE) ../../include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f ./$(NAME_LIB)

re: fclean all

.PHONY: all my clean fclean re
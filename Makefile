##
## EPITECH PROJECT, 2018
## makefile
## File description:
## This file is used for compliation of src and lib
##

SRC	=	./src/

MAIN_FILE = ./src/main.c

SRC_TEST = 	./tests/

NAME		=	my_ls
NAME_TEST	=	test_my_ls
LIB_PATH 	= ./lib/my/
INCLUDE_PATH = ./include/
LIB_NAME = libmy.a

CFLAGS	=	-W -Wall -Wextra -I $(INCLUDE_PATH) -L $(LIB_PATH) -lmy

OBJ	=	$(SRC:.c=.o)
OBJ_MAIN = $(MAIN_FILE:.c=.o)

$(NAME): $(OBJ) $(OBJ_MAIN)
		$(MAKE) -C $(LIB_PATH)
		gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) -g

all: $(NAME)

debug:
	gcc -o $(NAME) $(SRC) $(MAIN_FILE) $(CFLAGS) -g

tests_run:
	$(MAKE) -C $(LIB_PATH)
	gcc -o $(NAME_TEST) $(SRC_TEST) $(SRC) $(CFLAGS) -lcriterion --coverage -g

clean:
		rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)
		$(MAKE) -C $(LIB_PATH) clean

fclean:
		rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)
		rm -f $(NAME) $(NAME_TEST)
		$(MAKE) -C $(LIB_PATH) fclean

re:		fclean all

.PHONY: 	all clean fclean re debug

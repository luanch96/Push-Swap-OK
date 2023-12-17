NAME= push_swap

SRC		= 	mainpush.c ft_box_call.c ft_box_spawn.c	\
			ft_free_debug.c	ft_push_swap.c ft_nodeconfig.c \
			ft_push_two.c ft_reverse_rot.c ft_rotate_two.c \
			ft_sort_numbers.c  ft_swap_two.c ft_utils.c ft_utils2.c
			
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -rf

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
			
all: 	$(NAME)

clean:
			${RM} $(OBJ)

fclean:		clean 
			${RM} $(NAME) ${OBJ}

re:		fclean all

.PHONY: all clean fclean re


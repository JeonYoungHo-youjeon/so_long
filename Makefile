NAME		= so_long

SRCS		= main.c \
			  get_next_line.c \
			  get_next_line_utils.c \



OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= 
# -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		arch -x86_64 gcc -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		arch -x86_64 gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)
re			:	fclean all

.PHONY		:	all clean fclean re bonus


NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= so_long.c \
			  image.c \
			  key.c \
			  map.c \
			  utils.c \
			  get_next_line.c \
			  get_next_line_utils.c \



OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		arch -x86_64 make all -C $(LIBFT)/
		arch -x86_64 gcc -o $(NAME) $(OBJS) -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		arch -x86_64 gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus

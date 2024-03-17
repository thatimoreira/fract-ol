SRCS = 	srcs/fractol.c srcs/fractol_utils.c

INC = /usr/include
MLX_LIB = includes/minilibx-linux/
FRACT = includes/
#LIBFT = includes/libft

OBJS =	$(SRCS:.c=.o)

NAME =	fractol

CC =	cc
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = $(CFLAGS) -L$(MLX_LIB) -lmlx_Linux -L/usr/lib -I$(MLX_LIB) -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	 $(CC) $(OBJS) $(MLXFLAGS) -o $(NAME) 

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
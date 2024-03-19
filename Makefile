SRCS = 	srcs/fractol.c srcs/fractol_utils.c

INC = /usr/include
MLX_LIB = includes/minilibx-linux/
FRACT = includes/
LIBFT_PATH = includes/libft

OBJS =	$(SRCS:.c=.o)

NAME =	fractol

CC =	cc
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = $(CFLAGS) -L$(MLX_LIB) -lmlx_Linux -L/usr/lib -I$(MLX_LIB) -lXext -lX11 -lm -lz
LIBFT = $(LIBFT_PATH)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I mlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	 $(CC) $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C $(LIBFT_PATH)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C minilibx-linux

re:	fclean all

.PHONY: all clean fclean re

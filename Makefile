NAME =	fractol

CC =	cc
CFLAGS = -Wall -Wextra  -Wno-unused-variable -g # -Werror
LIBS = -lXext -lX11 -lm
RM =	rm -rf

INC = /usr/include
MLX = includes/minilibx-linux/libmlx.a
LIBFT = includes/libft/libft.a
SRC_DIR = srcs/
DRAW_DIR = draw_fractals/
OBJ_DIR = objs/

SRC = 	main.c fractol_init.c fractol_utils1.c fractol_utils2.c
DRAW_SRC = render_fractals.c render_utils.c render_mandelbrot.c #render_julia.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
DRAW_SRCS = $(addprefix $(DRAW_DIR), $(DRAW_SRC))
OBJS =	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS)) \
		$(patsubst $(DRAW_DIR)%.c,$(OBJ_DIR)%.o,$(DRAW_SRCS))

all:	$(NAME) #$(MLX) $(LIBFT)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	 	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(LIBS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)  #check	 again
				$(CC) $(CFLAGS) -I$(INC) -Imlx_linux -O3 -c $< -o $@

$(OBJ_DIR)%.o: $(DRAW_DIR)%.c
				@mkdir -p $(OBJ_DIR)  #check again
				$(CC) $(CFLAGS) -I$(INC) -Imlx_linux -O3 -c $< -o $@

$(MLX):
		@make -sC ./includes/minilibx-linux

$(LIBFT):
			@make -sC ./includes/libft/

clean:
		$(RM) $(OBJ_DIR)
		@make clean -C ./includes/minilibx-linux/
		@make clean -C ./includes/libft/

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(MLX)
		$(RM) $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re


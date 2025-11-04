NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iminilibx-linux

MLX_DIR		= minilibx-linux
MLX_LIB		= -L$(MLX_DIR) -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lz

SRCS		= main.c \
			  utils.c \
			  iter.c \
			  render.c \
			  handle.c \
			  init.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

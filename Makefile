NAME = cub3d

SRCS =  src/main.c \
		src/init_game.c \
		src/clean.c \
		src/parse_map.c \
		src/validate_map.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_LIB = minilibx-linux/libmlx_Linux.a
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -lX11 -lXext -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re

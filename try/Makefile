NAME = try

#dir
MLX_DIR = ../MLX42
LIBFT_DIR = ../libft

#files
SRC = main.c error.c
OBJ = $(SRC:%.c=%.o)

#libraies and headers
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS := -Iinclude -I$(MLX_DIR)/include -I$(LIBFT_DIR)

#flags
OS ?= $(shell uname)
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -fsanitize=address -fno-omit-frame-pointer

# switch to linux
ifeq ($(OS), Linux)
	MLXFLAGS := -lglfw -ldl -pthread -lm -Ofast
	CC = cc
	DEBUG_FLAGS += -fsanitize=leak
else ifeq ($(OS), Darwin)
	MLXFLAGS = -L/opt/homebrew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit -mmacosx-version-min=15.0
	CFLAGS += -mmacosx-version-min=15.0
	CC = clang
endif
#CFLAGS and MLXFLAGS with the last one for because of the -lglfw: link to the library file (?), is dedicated for 13.0 or older, but mine mac os is 15.0. so it has warning. Also the for the lglfw, ass -L/opt/homebrew/lib is to tell the linker to find it in such directory, instead of /user/local/lib. 

all: buildmlx buildlibft $(NAME)

buildmlx:
	git submodule update --init --recursive
	cmake $(MLX_DIR) -B $(MLX_DIR)/build
	cmake --build $(MLX_DIR)/build --parallel 4

buildlibft: 
	$(MAKE) -C $(LIBFT_DIR)


%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LIB) $(LIBFT) $(MLXFLAGS) -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)/build
	rm -f $(NAME)

re: fclean all

debug:fclean buildmlx buildlibft $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(LIBFT) $(DEBUG_FLAGS) $(MLXFLAGS) -o $(NAME) -lm

.PHONY: all, clean, fclean, re, buildmlx, buildlibft, debug
NAME			= so_long
BONUS_NAME		= so_long_bonus

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS		= -L/usr/include/minilibx-linux -lmlx -lXext -lX11

SRC				= mandatory/so_long.c mandatory/destroy.c \
					mandatory/map_parser/load_map.c mandatory/map_parser/map_check.c mandatory/map_parser/path_check.c \
					mandatory/graphics/textures.c mandatory/graphics/moves.c
BONUS_SRC		= bonus/so_long_bonus.c bonus/destroy_bonus.c \
					bonus/map_parser/load_map_bonus.c bonus/map_parser/map_check_bonus.c bonus/map_parser/path_check_bonus.c \
					bonus/graphics/textures_bonus.c bonus/graphics/moves_bonus.c

OBJ 			= $(SRC:.c=.o)
BONUS_OBJ		= $(BONUS_SRC:.c=.o)

LIBFT_DIR		= libft
LIBFT 			= $(LIBFT_DIR)/libft.a

INCLUDES		= -I includes -I $(LIBFT_DIR)

HEADER			= ./includes/so_long.h
BONUS_HEADER	= ./includes/so_long_bonus.h

RM			= rm -f

all: $(LIBFT) $(NAME)
bonus: $(LIBFT) $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)
$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(LIBFT) $(MLX_FLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
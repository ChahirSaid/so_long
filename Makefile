NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -L/usr/lib -lmlx -lXext -lX11
SRC			= so_long.c destroy.c \
				map_parser/load_map.c map_parser/map_check.c map_parser/path_check.c \
				graphics/textures.c

OBJ 		= $(SRC:.c=.o)

LIBFT_DIR	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I includes -I $(LIBFT_DIR)

HEADER		= ./includes/so_long.h

RM			= rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
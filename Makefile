NAME = so_long
INCLUDE = so_long.h
SRC = main.c controls.c images.c map.c map_errors_1.c map_errors_2.c game_over.c
OBJ_DIR = objs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

LIBFT = include/Libft/libft.a
PRINTF = include/Ft_Printf/libftprintf.a
GETNEXTLINE = include/Get_Next_Line/*c
MINILIBX = minilibx_linux/libmlx.a

all: export DISPLAY=localhost:0.0 $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GETNEXTLINE) $(MINILIBX) -lX11 -lXext -lm -lz -O3 -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C include/Libft -s

$(PRINTF):
	make -C include/Ft_Printf -s

$(MINILIBX):
	make -C minilibx_linux -s

clean:
	$(RM) $(OBJ_DIR)
	make -C include/Libft clean -s
	make -C include/Ft_Printf clean -s
	make -C minilibx_linux clean -s

fclean: clean
	$(RM) $(NAME)
	make -C include/Libft fclean -s
	make -C include/Ft_Printf fclean -s

re: fclean all

run: $(NAME)
	export DISPLAY=localhost:0.0 && ./$(NAME) maps/map1.ber

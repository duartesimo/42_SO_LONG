#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "stdbool.h"
# include "include/Libft/libft.h"
# include "include/Ft_Printf/ft_printf.h"
# include "include/Get_Next_Line/get_next_line.h"
# include "include/Libft/libft.h"
# include "minilibx_linux/mlx.h"

# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*tile;
	void	*wall;
	void	*player;
	void	*playerup;
	void	*playerdown;
	void	*playerleft;
	void	*playerright;
	void	*exit;
	void	*exitopen;
	void	*exitclosed;
	void	*item;
	char	**map;
	int		height;
	int		width;
	int		y;
	int		x;
	int		x_start;
	int		y_start;
	int		fd;
	int		player_num;
	int		item_num;
	int		exit_num;
	int		items;
	int		steps;
}	t_game;

int		read_map(char *map, t_game *game);
int		destroy_map(char **map);
int		controls(int key, t_game *game);
int		close_game(t_game *game);
void	validate_args(int argc, char **argv);
void	map_errors(char *the_map, t_game *game);
void	check_rectangular_map(t_game *game);
void	check_walls(t_game *game);
void	check_content(t_game *game);
void	create_images(t_game *game);
void	add_images(t_game *game);

#endif
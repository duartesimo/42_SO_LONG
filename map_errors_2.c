#include "so_long.h"

void	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error!\nInvalid number of arguments!\n");
		exit(1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error!\nInvalid map extension!\n");
		exit (1);
	}
}

static void	check_path(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'V')
		return ;
	game->map[y][x] = 'V';
	check_path(game, y + 1, x);
	check_path(game, y - 1, x);
	check_path(game, y, x + 1);
	check_path(game, y, x - 1);
}

static void	check_reachable(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x <= game->width)
		{
			if (game->map[y][x] == 'C' || game->map[y][x] == 'P'
							|| game->map[y][x] == 'E')
			{
				ft_printf("Error\nPath is blocked!\n");
				close_game(game);
			}
			x++;
		}
		y++;
	}
}

void	map_errors(char *the_map, t_game *game)
{
	check_rectangular_map(game);
	check_walls(game);
	check_content(game);
	check_path(game, game->y_start, game->x_start);
	check_reachable(game);
	destroy_map(game->map);
	ft_bzero(game, sizeof(t_game));
	read_map(the_map, game);
}

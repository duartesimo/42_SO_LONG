#include "so_long.h"

static int	line_len(const char *str)
{
	int	count;

	count = 0;
	while (*str && *str != '\n')
	{
		count++;
		str++;
	}
	return (count);
}

void	check_rectangular_map(t_game *game)
{
	int	i;
	int	first_row;

	first_row = line_len(game->map[0]);
	i = 1;
	while (i < game->height)
	{
		if (line_len(game->map[i]) != first_row)
		{
			ft_printf("Error!\nMap is not Rectangular!\n");
			close_game(game);
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_printf("Error!\nMap not surrounded by vertical walls!\n");
			close_game(game);
		}
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			ft_printf("Error!\nMap not surrounded by horizontal walls!\n");
			close_game(game);
		}
		i++;
	}
}

static void	count_stuff(t_game *game, int y, int x)
{
	const char	*valid;

	valid = "01PEC\n";
	if (ft_strchr(valid, game->map[y][x]) == NULL)
	{
		ft_printf("Error!\nInvalid stuff in Map!\n");
		close_game(game);
	}
	if (game->map[y][x] == 'C')
		game->item_num++;
	else if (game->map[y][x] == 'P')
	{
		game->player_num++;
		game->y_start = y;
		game->x_start = x;
	}
	else if (game->map[y][x] == 'E')
		game->exit_num++;
}

void	check_content(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x <= game->width)
		{
			count_stuff(game, y, x);
			x++;
		}
		y++;
	}
	if (!(game->player_num == 1 && game->exit_num == 1 && game->item_num >= 1))
	{
		ft_printf("Error\nWrong number of content items!\n");
		close_game(game);
	}
}

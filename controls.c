#include "so_long.h"

static int	finish_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (0);
	else if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->items--;
		game->map[y][x] = 'P';
		game->y = y;
		game->x = x;
		game->steps++;
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->items == 0)
		{
			ft_printf("You Won!\nTook you %d moves!\n", game->steps + 1);
			close_game(game);
		}
		game->y = y;
		game->x = x;
		game->steps++;
	}
	return (1);
}

static void	move(t_game *game, int y_offset, int x_offset)
{
	int	prev_y;
	int	prev_x;
	int	possible;

	prev_y = game->y;
	prev_x = game->x;
	possible = finish_move(game, game->y + y_offset, game->x + x_offset);
	if (!possible)
		return ;
	if (y_offset < 0)
		game->player = game->playerup;
	else if (y_offset > 0)
		game->player = game->playerdown;
	else if (x_offset < 0)
		game->player = game->playerleft;
	else if (x_offset > 0)
		game->player = game->playerright;
	if (game->map[prev_y][prev_x] != 'E')
		game->map[prev_y][prev_x] = '0';
	if (game->items == 0)
		game->exit = game->exitopen;
	add_images(game);
	ft_printf("Number of Moves: %i\n", game->steps);
}

int	controls(int key, t_game *game)
{
	if (key == ESC)
		close_game(game);
	else if (key == W)
		move(game, -1, 0);
	else if (key == S)
		move(game, 1, 0);
	else if (key == A)
		move(game, 0, -1);
	else if (key == D)
		move(game, 0, 1);
	return (0);
}

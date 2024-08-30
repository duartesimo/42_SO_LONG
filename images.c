#include "so_long.h"

static void	image_to_window(t_game *game, int y, int x, char c)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->player, x * 32, y * 32);
		game->y = y;
		game->x = x;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->item, x * 32, y * 32);
		game->items++;
	}
}

void	add_images(t_game *game)
{
	int	y;
	int	x;

	game->items = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->wall, x * 32, y * 32);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tile, x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->exit, x * 32, y * 32);
			else if (game->map[y][x] == 'P' || game->map[y][x] == 'C')
				image_to_window(game, y, x, game->map[y][x]);
			x++;
		}
		y++;
	}
}

void	create_images(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/wall.xpm", &x, &y);
	game->tile = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/tile.xpm", &x, &y);
	game->exitclosed = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/exit.xpm", &x, &y);
	game->exitopen = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/exitopen.xpm", &x, &y);
	game->item = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/item.xpm", &x, &y);
	game->playerup = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/playerup.xpm", &x, &y);
	game->playerdown = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/playerdown.xpm", &x, &y);
	game->playerleft = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/playerleft.xpm", &x, &y);
	game->playerright = mlx_xpm_file_to_image(game->mlx_ptr, 
			"images/playerright.xpm", &x, &y);
	game->player = game->playerdown;
	game->exit = game->exitclosed;
}

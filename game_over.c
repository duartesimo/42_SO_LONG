#include "so_long.h"

int	destroy_map(char **map)
{
	int	line;

	line = 0;
	while (map[line])
	{
		free(map[line]);
		line++;
	}
	free(map);
	return (0);
}

int	close_game(t_game *game)
{
	if (game->mlx_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->tile);
		mlx_destroy_image(game->mlx_ptr, game->wall);
		mlx_destroy_image(game->mlx_ptr, game->playerup);
		mlx_destroy_image(game->mlx_ptr, game->playerdown);
		mlx_destroy_image(game->mlx_ptr, game->playerleft);
		mlx_destroy_image(game->mlx_ptr, game->playerright);
		mlx_destroy_image(game->mlx_ptr, game->exitclosed);
		mlx_destroy_image(game->mlx_ptr, game->exitopen);
		mlx_destroy_image(game->mlx_ptr, game->item);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	destroy_map(game->map);
	exit(0);
	return (0);
}

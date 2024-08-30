#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	ft_bzero(&game, sizeof(t_game));
	read_map(argv[1], &game);
	map_errors(argv[1], &game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.width * 32),
			(game.height * 32), "So Long - The Game");
	create_images(&game);
	add_images(&game);
	mlx_key_hook(game.win_ptr, controls, &game);
	mlx_hook(game.win_ptr, 17, 0, close_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

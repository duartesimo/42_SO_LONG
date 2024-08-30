#include "so_long.h"

static int	width_of_map(char *string)
{
	int	i;
	int	width;

	width = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] != '\n')
			width++;
		i++;
	}
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height++;
	temporary = (char **)malloc(sizeof(char *) * (game->height + 1));
	temporary[game->height] = NULL;
	while (i < game->height - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
	{
		free(game->map);
	}
	game->map = temporary;
	return (1);
}

int	read_map(char *map, t_game *game)
{
	char	*readmap;

	game->fd = open(map, O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->width = width_of_map(game->map[0]);
	return (1);
}

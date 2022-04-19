#include "so_long.h"
int	game_exit(int key_code, t_game *game)
{
	if (key_code == ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		printf(RED"Game Exit\n"ENDC);
		exit (0);
	}
	return (0);
}
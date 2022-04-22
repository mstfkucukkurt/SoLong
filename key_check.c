#include "so_long.h"

int	key_check(int key_code, t_game *game)
{
	if (key_code == ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		printf(RED"Game Exit\n"ENDC);
		exit (0);
	}
	if (key_code == UP)
	{
		printf(RED"up\n"ENDC);
		up(game);
	}
	if (key_code == RIGHT)
	{
		printf(RED"RIGHT\n"ENDC);
		right(game);
	}
	if (key_code == LEFT)
	{
		printf(RED"LEFT\n"ENDC);
		left(game);
	}
	if (key_code == DOWN)
	{
		printf(RED"DOWN\n"ENDC);
		down(game);
	}
	return (0);
}
void right(t_game *game)
{
	t_image image;
    image.relative_path = "./img/karakter.xpm";
	image.wlx = *game;
	int i = game->player.y;
	int j = game->player.x + 48;
	if ((mapcheck(game,(i/48),(j/48)) != 1))
	{
		guncel(game);
		game->player.y = i;
		game->player.x = j;
		put_image(image,j,i);
	}
	
}
void guncel(t_game *game)
{
	t_image image;
	image.relative_path = "./img/floor.xpm";
	image.wlx = *game;
	int i = game->player.y;
	int j = game->player.x;
	put_image(image,j,i);
}
void left(t_game *game)
{
	t_image image;
    image.relative_path = "./img/karakter.xpm";
	image.wlx = *game;
	int i = game->player.y;
	int j = game->player.x - 48;
	if ((mapcheck(game,(i/48),(j/48)) != 1))
	{
		guncel(game);
		game->player.y = i;
		game->player.x = j;
		put_image(image,j,i);
	}
}
void up(t_game *game)
{
	t_image image;
    image.relative_path = "./img/karakter.xpm";
	image.wlx = *game;
	int i = game->player.y - 48;
	int j = game->player.x;
	if ((mapcheck(game,(i/48),(j/48)) != 1))
	{
		guncel(game);
		game->player.y = i;
		game->player.x = j;
		put_image(image,j,i);
	}
}
void down(t_game *game)
{
	t_image image;
    image.relative_path = "./img/karakter.xpm";
	image.wlx = *game;
	int i = game->player.y + 48;
	int j = game->player.x;
	if ((mapcheck(game,(i/48),(j/48)) != 1))
	{
		guncel(game);
		game->player.y = i;
		game->player.x = j;
		put_image(image,j,i);
	}
}
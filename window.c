#include "so_long.h"

int main(int argc,char **argv)
{
	t_game game;
	if (argc != 2)
	{
		printf(RED"Sadece 2 arguman girebilirsin\n");
		return (0);
	}
	ft_window_size(&game,argv);
	game.mlx = mlx_init(); //bağlantı kuruyor display ile software bağlantı
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y, "Hello world!");
	create_map(&game,argv);
	konumhesapla(&game);
	kontrol(&game);
	game.player.coin = 0;
	game.player.hareket = 0;
	mlx_hook(game.window, ON_KEYDOWN, 1L << 0, key_check, &game);
	mlx_loop(game.mlx);
}

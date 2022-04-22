#include "so_long.h"

int main(void)
{
	t_game game;
	t_platform a;
	a.path = "./map/map1.ber";
	game.mlx = mlx_init(); //bağlantı kuruyor display ile software bağlantı
	game.window = mlx_new_window(game.mlx, 1920, 1080, "Hello world!");
	/* game.player.x = 48;
	game.player.y = 192; */
	create_map(&game, a);
	konumhesapla(&game);
	game.player.coin = 0;
	mlx_hook(game.window, ON_KEYDOWN, 1L << 0, key_check, &game);
	mlx_loop(game.mlx);
}

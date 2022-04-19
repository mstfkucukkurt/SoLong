#include "so_long.h"

int main(void)
{
	t_game game;
	t_platform a;
	a.path = "./map/map.ber";
	game.mlx = mlx_init(); //bağlantı kuruyor display ile software bağlantı
	game.window = mlx_new_window(game.mlx, 1920, 1080, "Hello world!");
	mlx_hook(game.window, ON_KEYDOWN, 1L << 0, game_exit, &game);
	create_map(game, a);
	mlx_loop(game.mlx);
}

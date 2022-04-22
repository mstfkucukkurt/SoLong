#ifndef SO_LONG_H
# define SO_LONG_H

# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53

#include "minilibx/mlx.h"
#include "libft/libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_player
{
	int      x;
	int      y;
	int		coin;

}				t_player;
typedef struct	s_game
{
	void	*mlx;
	void	*window;
    char    **map;
	t_player   player;
	int	      coincheck;

}				t_game;
typedef struct s_image//put image fonksiyonu için lazım
{
	char*				relative_path;
	struct s_game		wlx;
	void 				*img;
	int					x;
	int 				y;
	int					img_height;
	int					img_width;
}	t_image;

typedef struct s_block //img dosyamdaki görüntüleri basmak için
{
	char	*name;
	char	*relative_path;
}	t_block;


typedef struct s_platform
{
	char	*path;
}	t_platform;
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	key_check(int key_code, t_game *game);
char *get_next_line(int fd);
void *myfree(void *str);
void create_map(t_game *wlx, t_platform platform);
void create_map_line(char *area, t_game *wlx, int i);
void *put_image(t_image image,int x,int y);
void ekranabas(t_game game,int i);
void right(t_game *game);
void down(t_game *game);
void left(t_game *game);
void up(t_game *game);
void guncel(t_game *game,int x,int y);
void d(t_game *game,t_image *image);
void	konumhesapla(t_game	*game);
int mapcheck(t_game *game,int i,int j);
#endif
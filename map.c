#include "so_long.h"

void *put_image(t_image image,int x,int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx, image.relative_path, &image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	return (image.img);
}

t_block set_block(char name)
{
	t_block maps[6];
	int i;

	maps[0] = (t_block){"1", "./img/duvar.xpm"};
	maps[1] = (t_block){"0", "./img/floor.xpm"};
	maps[2] = (t_block){"C", "./img/elma.xpm"};
	maps[3] = (t_block){"P", "./img/karakter.xpm"};
	maps[4] = (t_block){"E", "./img/exit.xpm"};
	maps[5] = (t_block){NULL, NULL};

	i = 0;
	while (maps[i].name != NULL)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break;
		}
		i++;
	}
	return (maps[5]);
}

void ekranabas(t_game game,int i)
{
    int j = 0;
    t_block map;
    t_image  image;
    image.wlx = game;
	int b = i;
	while (game.map[b])
	{
		while(game.map[b][j])
        {
			image.relative_path = "./img/floor.xpm";
            put_image(image,(j*48),(i*48));
        j++;
        }
    b++;
	}
	j = 0;
    while(game.map[i])
    {
        j = 0;
        while(game.map[i][j])
        {
            map = set_block(game.map[i][j]);
            image.relative_path = map.relative_path;
            put_image(image,(j*48),(i*48));
        j++;
        }
    i++;
    } 
}
void create_map_line(char *area, t_game *wlx, int i)
{
	int		j;
	t_image	image;
	image.wlx = *wlx;
	j = 0;
    wlx->map[i] = (char *)malloc(sizeof(char) * (9999));
    while(area[j])
    {
        if(area[j] == '\n')
            break;
    wlx->map[i][j] = area[j];
    j++; 
    }
	ekranabas(*wlx,i);
}
void create_map(t_game *wlx, t_platform platform)
{
	int		fd;
	char 	*area;
	int		i;
     wlx->map = (char **)malloc(sizeof(char *) * (9999));

	fd = open(platform.path, O_RDONLY);
	i = 0;
	while (i < 9999)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break;
		create_map_line(area, wlx, i);
		i++;
	}    
	close(fd);
}
void	konumhesapla(t_game	*game)
{
	int i = 0;
	int j = 0;
	 while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * 48;
				game->player.y = i * 48;
				break;
			}
        j++;
        }
    i++;
    } 
}
int mapcheck(t_game *game,int i,int j)
{
	if (game->map[i][j] == '1')
	{
		return(1);
	}
	return(0);
}
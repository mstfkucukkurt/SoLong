#include "so_long.h"

void *put_image(t_image image,int x,int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx, image.relative_path, &image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	return (image.img);
}
void	abc(char *error_msg)
{
	printf("%s", error_msg);
	exit(0);
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

int	ft_count_lines(int fd)
/* fd dosyasının kaç satır içerdiğini döndürür */
{
	int		linecount;
	char	buffer[0];
	int		bytes;

	buffer[0] = '\0';
	linecount = 1;
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if(bytes < 1)
			break;
		if (buffer[0] == '\n')
			linecount++;
	}
	return (linecount);
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

void create_map(t_game *wlx, char **argv)
{
	int		fd;
	char 	*area;
	int		i;
	
    wlx->map = (char **)malloc(sizeof(char *) * (9999));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i <= wlx->sizeofy)
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
	game->coincheck = 0;
	 while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
			if (game->map[i][j] == 'C')
				game->coincheck++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * 48;
				game->player.y = i * 48;
			}
        j++;
        }
    i++;
    } 
}
void  kontrol(t_game  *game)
{
	int i = 0;
	int j = 0;
	int coin = 0;
	int player;
	 while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
			if (game->map[i][j] == 'C')
				coin++;
			if (game->map[i][j] == 'P')
				player++;
        j++;
        }
    i++;
    }
	if(coin == 0)
		abc(RED"elma yok harita olusamadı\n"ENDC);
	
}
int mapcheck(t_game *game,int i,int j)
{
	if (game->map[i][j] == '1')
	{
		return(1);
	}		
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		printf(RED"ELMA SAYISI = %d\n"ENDC,game->player.coin);
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->coincheck)
		{
			printf(RED"ELMALARIN HEPSİNİ TOPLADIN MI SENCE ?\n"ENDC);
			return (1);
		}	
		exit(0);
	return (0);
	}
	return(0);
}
void	ft_window_size(t_game *data, char **argv)
/* pencere boyutunu bulacak ve bazı hataları kontrol edecek */
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		abc(RED"Error\nHarita bulunamadı"ENDC);
	if (strnstr(argv[1], ".ber", strlen(argv[1])) == NULL)
		abc(RED"Error\nHaritan .ber uzantılı degil\n"ENDC);
	data->size_x = (ft_line_length(fd) * 48);
	data->size_y = ft_count_lines(fd) * 48;
	data->sizeofx = data->size_x / 48;
	data->sizeofy = data->size_y / 48;
/* 	printf(RED"COİN****%d\n"ENDC,data->sizeofy);
	printf(RED"COİN****%d\n"ENDC,data->sizeofx); */
}
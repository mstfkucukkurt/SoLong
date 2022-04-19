#include "so_long.h"

void *put_image(t_image image)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx, image.relative_path, &image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, image.x, image.y);
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

void create_map_line(char *area, t_game wlx, int i)
{
	int		j;
	t_block map;
	t_image	image;

	image.wlx = wlx;
	j = 0;
	while (area[j] != '\0')
	{
		image.x = j * 48;
		image.y = i * 48;
		image.relative_path = "./img/floor.xpm";
		if (area[j] == '\n')
				break;
		put_image(image);
		j++;
	}
	j = 0;
	while (area[j] != '\0')
	{
		if(area[j] == '\n')
			break;	
		map = set_block(area[j]);
		image.x = j * 48;
		image.y = i * 48;
		image.relative_path = map.relative_path;
			put_image(image);
		j++;
	}
}

void create_map(t_game wlx, t_platform platform)
{
	int		fd;
	char 	*area;
	int		i;

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkucukku <mkucukku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:41:20 by mkucukku          #+#    #+#             */
/*   Updated: 2022/04/25 23:41:22 by mkucukku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	moves(t_game *game, char *str)
{
	t_image	image;

	image.relative_path = "./img/duvar.xpm";
	image.wlx = *game;
	put_image(image, 17 * 48, 0);
	put_image(image, 17 * 48 + 50, 0);
	mlx_string_put(image.wlx.mlx, image.wlx.window,
		17 * 48, 20, 0x00FF66, "MOVES:");
	mlx_string_put(image.wlx.mlx, image.wlx.window,
		17 * 48 + 50, 20, 0x00FF66, str);
	free(str);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/right.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/left.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/karakter.xpm";
	image.wlx = *game;
	i = game->player.y - 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/karakter.xpm";
	image.wlx = *game;
	i = game->player.y + 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

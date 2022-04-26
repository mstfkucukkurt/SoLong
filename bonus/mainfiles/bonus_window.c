/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkucukku <mkucukku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:36:41 by mkucukku          #+#    #+#             */
/*   Updated: 2022/04/25 23:36:44 by mkucukku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	message(BOLDRED"Oyun sonlandırıldı\n"ENDC, game);
	map_destroy(game);
	exit(0);
}

void	ft_window_size(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message(RED"Error\nDosya bulunamadı\n"ENDC, data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		message(RED"Error\nHaritan .ber uzantılı degil\n"ENDC, data);
	data->size_x = (ft_line_length(fd) * 48);
	data->size_y = ft_count_lines(fd) * 48;
}

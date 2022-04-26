/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkucukku <mkucukku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:44:16 by mkucukku          #+#    #+#             */
/*   Updated: 2022/04/25 23:44:18 by mkucukku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define BOLDRED    "\033[31m"
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define SIZE   48

# include "../minilibx/mlx.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		coin;
	int		hareket;

}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			coincheck;
	int			playercheck;
	int			exitcheck;
	size_t		size_x;
	int			size_y;
	t_player	player;
}				t_game;

typedef struct s_image
{
	char				*relative_path;
	struct s_game		wlx;
	void				*img;
	int					img_height;
	int					img_width;
}						t_image;

typedef struct s_block
{
	char	*name;
	char	*relative_path;
}	t_block;

size_t	ft_strlen(const char *str);
t_block	set_block(char name);

int		key_check(int key_code, t_game *game);
int		destroy_window(t_game *game);
int		ft_line_length(int fd);
int		ft_count_lines(int fd);

void	baslangic(t_game *game);
void	message(char *msg, t_game *game);
void	wall_control(t_game *game);
void	map_control(t_game *game);
void	game_control(t_game *game);
int		move_check(t_game *game, int i, int j);
void	ft_window_size(t_game *data, char **argv);
void	*myfree(void *str);
void	*put_image(t_image image, int x, int y);
void	create_map(t_game *game, int i);
void	create_floor(t_game game, int b);
void	create_map_length(char *area, t_game *game, int i);
void	create_map_line(t_game *game, char **argv);
void	update(t_game *game, int x, int y);
void	right(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	map_destroy(t_game	*game);

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

#endif

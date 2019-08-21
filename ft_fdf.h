/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:06:02 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/12 13:06:04 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define WIDTH 1000
# define HEIGHT 1000
# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BRESENHAM 0
# define WU 1
# define DEFAULT_ZOOM 2

typedef struct		s_line
{
	int				x;
	int				y;
	int				z;
}					t_line;

typedef struct		s_position
{
	int				width;
	int				height;
	int				zoom;
	int				dx;
	int				dy;
	double			alpha;
	double			beta;
	double			gamma;
	int				proj;
}					t_pos;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	struct s_map	*upper;
	struct s_map	*next;
	struct s_map	*next_line;
}					t_map;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
	char			*data;
	int				draw_mode;
	unsigned char	color[3];
	t_map			*map;
	t_pos			*pos;
}					t_win;

typedef struct		s_map_lines
{
	t_map			*first;
	t_map			*cur;
	t_map			*cur_prev;
	char			**nodes;
	int				j;
	char			**lines;
	t_map			*map;
	t_map			*prev_line;
	int				i;
}					t_map_lines;

void				bresenham_hight(t_win *win, t_line *l0, t_line *l1);
void				bresenham_low(t_win *win, t_line *l0, t_line *l1);
void				wu_low(t_win *win, t_line *l0, t_line *l1);
void				wu_hight(t_win *win, t_line *l0, t_line *l1);
t_map				*get_last(t_map *map);
void				start_fdf(char *buf);
t_map				*make_map(char *buf);
int					check_map(int fd, char **buf);
int					free_map(t_map *map);
t_map				*new_node(int x, int y, int z);
int					set_colors(unsigned char o, unsigned char r, \
				unsigned char g, unsigned char b);
void				draw_line(t_win *win, t_map *map1, t_map *map2);
void				make_image(t_win *win);
void				find_position(t_win *win);
int					key_event(int key_code, t_win *win);
void				angle(int *x, int *y, int *z, t_win *win);
int					zoom(int key_code, \
				t_win *win);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:46:54 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/16 13:46:56 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int		close_window(void *param)
{
	(void)param;
	exit(0);
}

void			make_image(t_win *win)
{
	t_map		*cur;

	cur = win->map;
	while (cur)
	{
		if (cur->next_line)
		{
			if (cur->upper)
				draw_line(win, cur->upper, cur);
			cur = cur->next_line;
			continue ;
		}
		if (cur->upper)
			draw_line(win, cur->upper, cur);
		if (cur->next)
			draw_line(win, cur, cur->next);
		cur = cur->next;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	ft_bzero(win->data, WIDTH * HEIGHT * 4);
}

void			start_fdf(char *buf)
{
	t_win	*win;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		return ;
	if (!(win->mlx = mlx_init()))
		return ;
	if (!(win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "FDF")))
		return ;
	if (!(win->map = make_map(buf)))
		return ;
	if (!(win->img = mlx_new_image(win->mlx, WIDTH, HEIGHT)))
		return ;
	if (!(win->data = mlx_get_data_addr(win->img, \
	&win->bpp, &win->size_line, &win->endian)))
		return ;
	find_position(win);
	ft_bzero(win->data, WIDTH * HEIGHT * 4);
	make_image(win);
	mlx_hook(win->win, 17, 0, close_window, win);
	mlx_hook(win->win, 2, 0, key_event, win);
	mlx_loop(win->mlx);
}

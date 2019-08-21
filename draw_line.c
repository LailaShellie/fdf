/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:36:53 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/13 12:36:54 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	add_position(t_win *win, t_line *l0, t_line *l1)
{
	l0->x = (l0->x - win->pos->width / 2) * win->pos->zoom;
	l1->x = (l1->x - win->pos->width / 2) * win->pos->zoom;
	l0->y = (l0->y - win->pos->height / 2) * win->pos->zoom;
	l1->y = (l1->y - win->pos->height / 2) * win->pos->zoom;
	l0->z *= win->pos->zoom;
	l1->z *= win->pos->zoom;
	angle(&l0->x, &l0->y, &l0->z, win);
	angle(&l1->x, &l1->y, &l1->z, win);
	l0->x += win->pos->dx + WIDTH / 2;
	l0->y += win->pos->dy + WIDTH / 2;
	l1->x += win->pos->dx + HEIGHT / 2;
	l1->y += win->pos->dy + HEIGHT / 2;
}

void	init_line(t_line *l0, t_line *l1, t_map *map0, t_map *map1)
{
	l0->x = map0->x;
	l0->y = map0->y;
	l0->z = map0->z;
	l1->x = map1->x;
	l1->y = map1->y;
	l1->z = map1->z;
}

void	draw_line(t_win *win, t_map *map0, t_map *map1)
{
	t_line l0;
	t_line l1;

	init_line(&l0, &l1, map0, map1);
	add_position(win, &l0, &l1);
	if (abs(l1.y - l0.y) < abs(l1.x - l0.x))
	{
		if (l0.x > l1.x)
			win->draw_mode == WU ? wu_low(win, &l1, &l0) \
			: bresenham_low(win, &l1, &l0);
		else
			win->draw_mode == WU ? wu_low(win, &l0, &l1) \
			: bresenham_low(win, &l0, &l1);
	}
	else
	{
		if (l0.y > l1.y)
			win->draw_mode == WU ? wu_hight(win, &l1, &l0) \
			: bresenham_hight(win, &l1, &l0);
		else
			win->draw_mode == WU ? wu_hight(win, &l0, &l1) \
			: bresenham_hight(win, &l0, &l1);
	}
}

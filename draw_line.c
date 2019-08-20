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

void	plot(int x, int y, float o, t_win *win)
{
	int 	*mas;
	int 	color;

	color = set_colors(255 * o, 255, 0, 255);
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;
	mas = (int *)win->data;
	mas[x + y * win->size_line / 4] = color;
}

void	draw_hight(t_win *win, t_line *map0, t_line *map1)
{
	float	grad;
	float	x;

	if (map1->x - map0->x)
		grad = (float)(map1->x - map0->x) / (float)(map1->y - map0->y);
	else
		grad = 0;
	plot(map0->x, map0->y, 0, win);
	plot(map1->x, map1->y, 0, win);
	x = map0->x + grad;
	while (map0->y < map1->y)
	{
		plot(x, (int)map0->y, (x - floor(x)), win);
		plot(x + 1, (int)(map0->y), 1 - (x - floor(x)), win);
		map0->y += 1;
		x += grad;
	}
//	int dx = x1 - x0;
//	int dy = y1 - y0;
//	int xi = 1;
//	int d;
//
//	if (dx < 0)
//	{
//		xi = -1;
//		dx = -dx;
//	}
//	d = 2 * dx - dy;
//	int y = y0;
//	int x = x0;
//	while (y < y1)
//	{
//		plot(x, y, 0, win);
//		if (d > 0)
//		{
//			x = x + xi;
//			d = d - 2 * dy;
//		}
//		d = d + 2 * dx;
//		++y;
//	}
}

void	draw_low(t_win *win, t_line *map0, t_line *map1)
{
	float	grad;
	float	y;

	if (map1->x - map0->x)
		grad = (float)(map1->y - map0->y) / (float)(map1->x - map0->x);
	else
		grad = 0;
	plot(map0->x, map0->y, 0, win);
	plot(map1->x, map1->y, 0, win);
	y = map0->y + grad;
	while (++map0->x < map1->x)
	{
		plot(map0->x, (int)y, (y - floor(y)), win);
		plot(map0->x, (int)(y + 1), 1 - (y - floor(y)), win);
		y += grad;
	}
//	int dx = x1 - x0;
//	int dy = y1 - y0;
//	int yi = 1;
//	int d;
//
//	if (dy < 0)
//	{
//		yi = -1;
//		dy = -dy;
//	}
//	d = 2 * dy - dx;
//	int y = y0;
//	int x = x0;
//	while (x < x1)
//	{
//		plot(x, y, 0, win);
//		if (d > 0)
//		{
//			y = y + yi;
//			d = d - 2 * dx;
//		}
//		d = d + 2 * dy;
//		++x;
//	}
}

void	add_position(t_win *win, t_line *l0, t_line *l1)
{
	l0->x *= win->pos->zoom;
	l0->y *= win->pos->zoom;
	l0->z *= win->pos->zoom;
	l1->x *= win->pos->zoom;
	l1->y *= win->pos->zoom;
	l1->z *= win->pos->zoom;
	angle(&l0->x, &l0->y, &l0->z, win);
	angle(&l1->x, &l1->y, &l1->z, win);
	l0->x += win->pos->dx;
	l0->y += win->pos->dy;
	l1->x += win->pos->dx;
	l1->y += win->pos->dy;
	l0->x += WIDTH / 2 - win->pos->width * win->pos->zoom / 2;
	l0->y += HEIGHT / 2 - win->pos->height * win->pos->zoom / 2;
	l1->x += WIDTH / 2 - win->pos->width * win->pos->zoom / 2;
	l1->y += HEIGHT / 2 - win->pos->height * win->pos->zoom / 2;
}

void	draw_line(t_win *win, t_map *map0, t_map *map1)
{
	t_line l0;
	t_line l1;

	l0.x = map0->x;
	l0.y = map0->y;
	l0.z = map0->z;
	l1.x = map1->x;
	l1.y = map1->y;
	l1.z = map1->z;
	add_position(win, &l0, &l1);
	if (abs(l1.y - l0.y) < abs(l1.x - l0.x))
	{
		if (l0.x > l1.x)
			draw_low(win, &l1, &l0);
		else
			draw_low(win, &l0, &l1);
	}
	else
	{
		if (l0.y > l1.y)
			draw_hight(win, &l1, &l0);
		else
			draw_hight(win, &l0, &l1);
	}
}
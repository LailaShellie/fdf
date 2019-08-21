/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:06:28 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/21 18:06:29 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void		plot(int x, int y, float o, t_win *win)
{
	int		*mas;
	int		color;

	color = set_colors(255 * o, win->color[0], win->color[1], win->color[2]);
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	mas = (int *)win->data;
	mas[x + y * win->size_line / 4] = color;
}

void			wu_low(t_win *win, t_line *l0, t_line *l1)
{
	float	grad;
	float	y;

	if (l1->x - l0->x)
		grad = (float)(l1->y - l0->y) / (float)(l1->x - l0->x);
	else
		grad = 0;
	plot(l0->x, l0->y, 0, win);
	plot(l1->x, l1->y, 0, win);
	y = l0->y + grad;
	while (++l0->x < l1->x)
	{
		plot(l0->x, (int)y, (y - floor(y)), win);
		plot(l0->x, (int)(y) + 1, 1 - (y - floor(y)), win);
		y += grad;
	}
}

void			wu_hight(t_win *win, t_line *l0, t_line *l1)
{
	float	grad;
	float	x;

	if (l1->x - l0->x)
		grad = (float)(l1->x - l0->x) / (float)(l1->y - l0->y);
	else
		grad = 0;
	plot(l0->x, l0->y, 0, win);
	plot(l1->x, l1->y, 0, win);
	x = l0->x + grad;
	while (++l0->y < l1->y)
	{
		plot(x, (int)l0->y, (x - floor(x)), win);
		plot(x + 1, (int)(l0->y), 1 - (x - floor(x)), win);
		x += grad;
	}
}

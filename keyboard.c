/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:50:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/19 18:50:16 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int				zoom(int key_code, t_win *win)
{
	if (key_code == 78)
	{
		if (win->pos->zoom != 1)
			win->pos->zoom -= 1;
	}
	else if (key_code == 69)
	{
		win->pos->zoom += 1;
	}
	return (0);
}

int				color(int key_code, t_win *win)
{
	if (key_code == 12)
		win->color[0] += 5;
	if (key_code == 0)
		win->color[0] -= 5;
	if (key_code == 13)
		win->color[1] += 5;
	if (key_code == 1)
		win->color[1] -= 5;
	if (key_code == 14)
		win->color[2] += 5;
	if (key_code == 2)
		win->color[2] -= 5;
	return (0);
}

int				rotate(int key_code, t_win *win)
{
	if (key_code == 86)
		win->pos->alpha -= 0.05;
	else if (key_code == 88)
		win->pos->alpha += 0.05;
	else if (key_code == 83)
		win->pos->beta -= 0.05;
	else if (key_code == 92)
		win->pos->beta += 0.05;
	else if (key_code == 91)
		win->pos->gamma -= 0.05;
	else if (key_code == 84)
		win->pos->gamma += 0.05;
	return (0);
}

int				move(int key_code, t_win *win)
{
	if (key_code == 123)
		win->pos->dx += 10;
	else if (key_code == 124)
		win->pos->dx -= 10;
	if (key_code == 125)
		win->pos->dy -= 10;
	else if (key_code == 126)
		win->pos->dy += 10;
	return (0);
}

int				key_event(int key_code, t_win *win)
{
	if (key_code == 53)
		exit(0);
	if ((key_code >= 0 && key_code <= 4) \
		|| (key_code >= 12 && key_code <= 15))
		color(key_code, win);
	if (key_code >= 123 && key_code <= 126)
		move(key_code, win);
	if (key_code == 69 || key_code == 78)
		zoom(key_code, win);
	if (key_code == 83 || key_code == 92 || key_code == 91 || key_code == 84
		|| key_code == 88 || key_code == 86)
		rotate(key_code, win);
	if (key_code == 49)
	{
		win->pos->proj = win->pos->proj == 1 ? 0 : 1;
		win->pos->gamma = 0;
		win->pos->alpha = 0;
		win->pos->beta = 0;
	}
	if (key_code == 48)
		win->draw_mode = win->draw_mode == 0 ? 1 : 0;
	mlx_clear_window(win->mlx, win->win);
	make_image(win);
	return (0);
}

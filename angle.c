/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:04:30 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/20 17:04:32 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	rotate_x(int *y, int *z, t_win *win)
{
	int prev_y;
	int prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(win->pos->alpha) + prev_z * sin(win->pos->alpha);
	*z = prev_z * cos(win->pos->alpha) - prev_y * sin(win->pos->alpha);
}

void	rotate_y(int *x, int *z, t_win *win)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(win->pos->beta) + prev_z * sin(win->pos->beta);
	*z = -prev_x * sin(win->pos->beta) + prev_z * cos(win->pos->beta);
}

void 	rotate_z(int *x, int *y, t_win *win)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(win->pos->gamma) - prev_y * sin(win->pos->gamma);
	*y = prev_x * sin(win->pos->gamma) + prev_y * cos(win->pos->gamma);
}

void angle(int *x, int *y, int *z, t_win *win)
{
	int prev_x;
	int prev_y;
	int prev_z;

	rotate_x(y, z, win);
	rotate_y(x, z, win);
	rotate_z(x, y, win);
	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	if (win->pos->proj == 1)
	{
		*x = (prev_x - prev_y) * cos(0.46373398);
		*y = (prev_x + prev_y) * sin(0.46373398) - prev_z;
	}
}
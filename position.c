/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:06:21 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/20 14:06:22 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static	void	find_height(t_win *win)
{
	t_map		*cur;

	cur = win->map;
	win->pos->height++;
	while (cur)
	{
		if (cur->next_line)
		{
			win->pos->height++;
			cur = cur->next_line;
			continue ;
		}
		cur = cur->next;
	}
}

static	void	find_width(t_win *win)
{
	t_map		*cur;

	cur = win->map;
	while (cur)
	{
		win->pos->width++;
		cur = cur->next;
	}
}

void			find_position(t_win *win)
{
	t_pos *pos;

	if (!(pos = (t_pos *)ft_memalloc(sizeof(t_pos))))
		return ;
	win->pos = pos;
	win->color[0] = 255;
	win->color[1] = 255;
	win->color[2] = 255;
	pos->zoom = 15;
	pos->dx = 0;
	pos->dy = 0;
	pos->alpha = 0.00;
	pos->beta = 0.00;
	pos->gamma = 0.00;
	pos->proj = 0;
	find_height(win);
	find_width(win);
}

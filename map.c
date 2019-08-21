/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 21:28:16 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/21 21:28:17 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_map		*get_last(t_map *map)
{
	while (map->next)
		map = map->next;
	return (map);
}

int			free_map(t_map *map)
{
	t_map *cur;
	t_map *tmp;

	if (!map)
		return (0);
	cur = map;
	while (cur)
	{
		tmp = 0;
		if (cur->next_line)
		{
			tmp = cur;
			free_map(cur->next_line);
			free(tmp);
			return (0);
		}
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	return (0);
}

t_map		*new_node(int x, int y, int z)
{
	t_map		*new;

	if (!(new = (t_map *)ft_memalloc(sizeof(t_map))))
		return (0);
	new->x = x;
	new->y = y;
	new->z = z;
	new->upper = 0;
	new->next = 0;
	new->next_line = 0;
	return (new);
}

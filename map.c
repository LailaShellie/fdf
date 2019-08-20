/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:07:28 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/15 18:07:29 by lshellie        6 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_map		*get_last(t_map *map)
{
	while (map->next)
		map = map->next;
	return (map);
}

//void isoi(int *x, int *y, int z)
//{
//	int previous_x;
//	int previous_y;
//
//	previous_x = *x;
//	previous_y = *y;
//	*x = (previous_x - previous_y) * cos(0.523599);
//	*y = (previous_x + previous_y) * sin(0.523599) - z;
//}
//
//void		iso_map(t_map *map)
//{
//	while (map)
//	{
//		if (!map->next)
//		{
//			isoi(&map->x, &map->y, map->z);
//			map = map->next_line;
//			continue ;
//		}
//		isoi(&map->x, &map->y, map->z);
//		map = map->next;
//	}
//}
//
//void		size_map(t_map *map)
//{
//	while (map)
//	{
//		if (!map->next)
//		{
//			map->x *= 10;
//			map->y *= 10;
//			map->z *= 1;
//			map->x += 700;
//			map->y += 100;
//			map = map->next_line;
//			continue ;
//		}
//		map->z *= 1;
//		map->x *= 10;
//		map->y *= 10;
//		map->x += 700;
//		map->y += 100;
//		map = map->next;
//	}
//}

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
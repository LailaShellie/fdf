/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:47:09 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/16 14:44:11 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		init_lines(t_map_lines *m_l, t_map *prev_line)
{
	m_l->first = 0;
	m_l->cur = 0;
	m_l->cur_prev = prev_line;
	m_l->nodes = 0;
	m_l->j = -1;
	m_l->map = 0;
	m_l->i = -1;
	m_l->lines = 0;
	m_l->prev_line = 0;
}

t_map		*make_node(char *str, int y, int x)
{
	t_map	*new;
	int		z;

	z = -1;
	while (str[++z])
	{
		if (str[z] == ',')
			str[z] = 0;
	}
	z = ft_atoi(str);
	if (!(new = new_node(x, y, z)))
		return (0);
	return (new);
}

void		set_prev(t_map *lst, t_map *prev)
{
	t_map	*first;
	t_map	*prev_last;

	first = lst;
	if (prev)
	{
		prev_last = get_last(prev);
		prev_last->next_line = first;
	}
	while (lst)
	{
		lst->upper = prev;
		lst = lst->next;
		if (prev)
			prev = prev->next;
	}
}

t_map		*make_line(t_map *prev_line, char *str, int y)
{
	t_map_lines		m;

	init_lines(&m, prev_line);
	if (!(m.nodes = ft_strsplit(str, ' ')))
		return (0);
	while (m.nodes[++m.j])
	{
		if (!m.first)
		{
			m.first = make_node(m.nodes[m.j], y, m.j);
			m.cur = m.first;
		}
		else if (m.first)
		{
			m.cur->next = make_node(m.nodes[m.j], y, m.j);
			m.cur = m.cur->next;
		}
	}
	set_prev(m.first, prev_line);
	ft_free_mas(m.nodes, m.j);
	return (m.first);
}

t_map		*make_map(char *buf)
{
	t_map_lines	lines;

	init_lines(&lines, 0);
	if (!(lines.lines = ft_strsplit(buf, '\n')))
		return (0);
	while (lines.lines[++lines.i])
	{
		if (!lines.map)
		{
			lines.map = make_line(lines.prev_line, \
			lines.lines[lines.i], lines.i);
			lines.prev_line = lines.map;
		}
		else
			lines.prev_line = make_line(lines.prev_line, \
			lines.lines[lines.i], lines.i);
	}
	ft_free_mas(lines.lines, lines.i);
	return (lines.map);
}

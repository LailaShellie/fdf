/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:43:37 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/15 17:43:38 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

char	*ft_strjoin_n(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 1 + 1;
	if (!(str = (char *)ft_memalloc(sizeof(str) * len)))
		return (0);
	while (i < len1)
		str[i++] = *s1++;
	str[i++] = '\n';
	while (i < len)
		str[i++] = *s2++;
	str[len] = 0;
	return (str);
}

int		check_color(char *str)
{
	if (str[0] != '0' || str[1] != 'x' || ft_strlen(str) != 8)
		return (0);
	str += 2;
	while (*str)
	{
		if (*str < 'A' || *str > 'F')
			return (0);
		++str;
	}
	return (1);
}

int		check_z(char *str)
{
	if (*str == '-')
		++str;
	while (*str && *str != ',')
	{
		if (*str < '0' || *str > '9')
			return (0);
		++str;
	}
	if (*str == ',')
		return (check_color(++str));
	return (1);
}

int		check_line(char *str, int *num)
{
	char	**tab;
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	if (!(tab = ft_strsplit(str, ' ')))
		return (0);
	while (tab[i])
	{
		if (flag)
			flag = check_z(tab[i]);
		++i;
	}
	ft_free_mas(tab, i);
	if (*num == 0)
		*num = i;
	else if ((*num != 0 && i != *num) || !flag)
		return (0);
	return (1);
}

int		check_map(int fd, char **buf)
{
	char	*str;
	int		num;
	char	*tmp;

	num = 0;
	str = 0;
	while (get_next_line(fd, &str) > 0)
	{
		if (!check_line(str, &num))
		{
			free(str);
			return (0);
		}
		if (*buf)
		{
			tmp = *buf;
			*buf = ft_strjoin_n(tmp, str);
			free(tmp);
		}
		else if (!(*buf))
			*buf = ft_strdup(str);
		free(str);
		str = 0;
	}
	return (1);
}

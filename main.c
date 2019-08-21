/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:06:09 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/12 13:06:10 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		set_colors(unsigned char o, unsigned char r, \
			unsigned char g, unsigned char b)
{
	int i;
	int tmp;
	int res;
	int j;

	i = 0;
	res = 0;
	tmp = 0;
	j = 0;
	while (i <= 31)
	{
		tmp = (i >= 0 && i <= 7) ? b : tmp;
		tmp = (i >= 8 && i <= 15) ? g : tmp;
		tmp = (i >= 16 && i <= 23) ? r : tmp;
		tmp = (i >= 24 && i <= 31) ? o : tmp;
		j = 0;
		while (j <= 7)
		{
			if (tmp & (1 << j))
				res |= 1 << i;
			++i;
			++j;
		}
	}
	return (res);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*buf;

	buf = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fdf [target_file]\n");
		exit(0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		exit(0);
	}
	if (!check_map(fd, &buf))
	{
		free(buf);
		ft_putstr("Error\n");
		exit(0);
	}
	start_fdf(buf);
	free(buf);
	exit(0);
}

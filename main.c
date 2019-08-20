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
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_bits(int octet)
{
	int i = 31;

	printf("    O        R        G       B\n");
	while (i >= 0)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (i % 8 == 0 && i != 1 && i)
			write(1, "|", 1);
		--i;
	}
}

int		set_colors(unsigned char O, unsigned char R, unsigned char G, unsigned char B)
{
	int i = 0;
	int tmp;
	int res;
	int j;

	res = 0;
	tmp = 0;
	j = 0;
	while (i <= 31)
	{
		tmp = (i >= 0 && i <= 7) ? B : tmp;
		tmp = (i >= 8 && i <= 15) ? G : tmp;
		tmp = (i >= 16 && i <= 23) ? R : tmp;
		tmp = (i >= 24 && i <= 31) ? O : tmp;
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
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return (0);
	}
	if (!check_map(fd, &buf))
	{
		free(buf);
		ft_putstr("Error\n");
		return (0);
	}
	start_fdf(buf);
	free(buf);
	return (0);
}
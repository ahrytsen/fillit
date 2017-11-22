/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:01:11 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/22 20:18:31 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [source_file]");
	exit(0);
}

int		ft_minsqr(int amount)
{
	int minsqr;

	minsqr = 2;
	while ((minsqr * minsqr) < (amount * 4))
		minsqr++;
	return (minsqr);
}

int		ft_solve(t_etr *figures, t_16bit *map, int sqr_size)
{
	if (!figures->value)
		return (1);
	figures->y = 0;
	while (figures->y + figures->h <= sqr_size)
	{
		figures->x = 0;
		while (figures->x + figures->w <= sqr_size)
		{
			if (!(*(t_64bit*)(map + figures->y) 
				  & figures->value >> figures->x))
			{
				*(t_64bit*)(map + figures->y) |= figures->value >> figures->x;
				if (ft_solve(figures + 1, map, sqr_size))
					return (1);
				*(t_64bit*)(map + figures->y) ^= figures->value >> figures->x;
			}
			figures->x++;
		}
		figures->y++;
	}
	figures->x = 0;
	figures->y = 0;
	return (0);
}

void	ft_dbg(t_etr *figures)
{
	while (figures->value)
	{
		for(int k = 63; k >= 0; --k)
		{
			printf("%d", figures->value & (1L << k) ? 1 : 0);
			!(k % 16) ? printf("\n") : 0;
		}
		printf("\nid = %c\nhigh = %d\nweigh = %d\nx = %d\ny = %d\n\n\n",
			   figures->id, figures->h, figures->w, figures->x, figures->y);
		figures++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		amount;
	t_etr	figures[27];
	int		sqr_size;
	t_16bit	map[16];

	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	ft_bzero(figures, sizeof(t_etr) * 27);
	ft_bzero(map, sizeof(t_16bit) * 16);
	amount = ft_reader(fd, figures);
	sqr_size = ft_minsqr(amount);
	while (!ft_solve(figures, map, sqr_size) && sqr_size < 14)
	{
		ft_bzero(map, sizeof(t_16bit) * 19);
		sqr_size++;
	}
	if (sqr_size == 14)
		ft_error();
	ft_dbg(figures);
	ft_output(figures, sqr_size);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:01:11 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/23 19:12:16 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

static void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [source_file]");
	exit(0);
}

static int	ft_minsqr(int amount)
{
	int minsqr;

	minsqr = 2;
	while ((minsqr * minsqr) < (amount * 4))
		minsqr++;
	return (minsqr);
}

void		ft_dbg(t_etr *figures)
{
	while (figures->value)
	{
		for (int k = 63; k >= 0; --k)
		{
			printf("%d", figures->value & (1L << k) ? 1 : 0);
			!(k % 16) ? printf("\n") : 0;
		}
		printf("\nid = %c\nhigh = %d\nweigh = %d\nx = %d\ny = %d\n\n\n",
			  figures->id, figures->h, figures->w, figures->x, figures->y);
		figures++;
	}
}

int			main(int ac, char **av)
{
	int		fd;
	int		amount;
	t_etr	*figures;
	int		sqr_size;
	t_16bit	*map;

	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	figures = (t_etr*)malloc(sizeof(t_etr) * 27);
	map = (t_16bit*)malloc(sizeof(t_16bit) * 16);
	if (fd == -1 || !figures || !map)
		ft_error();
	ft_bzero(figures, sizeof(t_etr) * 27);
	ft_bzero(map, sizeof(t_16bit) * 16);
	amount = ft_reader(fd, figures);
	sqr_size = ft_minsqr(amount);
	while (!ft_solve(figures, map, sqr_size) && sqr_size < 14)
	{
		ft_bzero(map, sizeof(t_16bit) * 16);
		sqr_size++;
	}
	if (sqr_size == 16)
		ft_error();
	ft_dbg(figures);
	ft_output(figures, sqr_size);
	return (0);
}

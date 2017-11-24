/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:01:11 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/24 21:13:04 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	figures = (t_etr*)ft_memalloc(sizeof(t_etr) * 27);
	map = (t_16bit*)ft_memalloc(sizeof(t_16bit) * 16);
	if (fd == -1 || !figures || !map)
		ft_error();
	amount = ft_reader(fd, figures);
	sqr_size = ft_minsqr(amount);
	while (!ft_solve(figures, map, sqr_size) && sqr_size++ < 14)
		ft_bzero(map, sizeof(t_16bit) * 16);
	if (sqr_size == 14)
		ft_error();
	ft_output(figures, sqr_size);
	sleep(30);
	return (0);
}

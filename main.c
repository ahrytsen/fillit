/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:01:11 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/16 19:05:50 by ahrytsen         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	int	fd;
	t_list *tetriminos;

	tetriminos = NULL;
	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	ft_tetrlst(fd, &tetriminos);
	ft_print_dbg(&tetriminos);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:01:11 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/19 18:04:13 by ahrytsen         ###   ########.fr       */
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
	int		fd;
	int		amount;
	t_map	*matrix;

	matrix = NULL;
	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	amount = ft_reader(fd, matrix);
	//ft_print_matrix(matrix);
	return (0);
}

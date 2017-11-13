/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:01:11 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/13 21:16:46 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	g_valid_form[19] = {
0b1111000000000000 0000000000000000 00000000000000000 000000000000000,
0b1111000000000000 0000000000000000 00000000000000000 000000000000000,

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
	t_list *tetrimos;
	int     amount;

	tetrimos = NULL;
	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	amount = ft_tetrlst(fd, &tetrimos);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:43:40 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/21 21:00:41 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_print(char **square, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(square[i][j]);
		ft_putchar('\n');
	}
}

void		ft_output(t_etr *figures, int size)
{
	int		i;
	int		j;
	char	**square;

	square = (char**)ft_memalloc(sizeof(char*) * size);
	i = -1;
	while (++i < size)
		square[i] = (char*)ft_memalloc(sizeof(char) * size);
	i = -1;
	while (++i < size)
		ft_memset(square[i], '.', size);
	while (figures->value)
	{
		i = figures->y - 1;
		while (++i < (figures->y + figures->w))
		{
			j = figures->x - 1;
			while (++j < (figures->x + figures->h))
				figures->value & (1L << (63 - (i * 16 + j))) ?
					square[i][j] = figures->id : 0;
		}
		figures++;
	}
	ft_print(square, size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:43:40 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/23 18:43:53 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_fill_sqr(char **square, const t_etr *figures)
{
	int		i;
	int		j;
	int		h;
	int		w;

	i = figures->y - 1;
	h = 0;
	while (++i < (figures->y + figures->h))
	{
		w = 0;
		j = figures->x - 1;
		while (++j < (figures->x + figures->w))
			figures->value & (1L << (63 - (h * 16 + w++))) ?
				square[i][j] = figures->id : 0;
		h++;
	}
}

void		ft_output(const t_etr *figures, const int size)
{
	int		i;
	int		j;
	char	**square;

	if (!(square = (char**)ft_memalloc(sizeof(char*) * size)))
		ft_error();
	i = -1;
	while (++i < size)
		if (!(square[i] = (char*)ft_memalloc(sizeof(char) * size)))
			ft_error();
	i = -1;
	while (++i < size)
		ft_memset(square[i], '.', size);
	while (figures->value)
		ft_fill_sqr(square, figures++);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(square[i][j]);
		ft_putchar('\n');
	}
}

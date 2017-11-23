/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:47:04 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/23 19:56:09 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void dbg_map(t_16bit *map)
{
	for (int k = 255; k >= 0; --k)
	{
		printf("%d", *(t_64bit*)map & (1L << k) ? 1 : 0);
		!(k % 16) ? printf("\n") : 0;
		!(k % 64) ? map +=4 : 0;
	}
}

inline static void	ft_switch_figure(t_etr *figures, t_16bit *map)
{
	dbg_map(map);
	printf("\n");
	*(t_64bit*)(map - figures->y) ^= figures->value >> figures->x;
	dbg_map(map);
	printf("--- SWITCH --- \n\n");
}

inline static int	ft_try_to_fill(t_etr *figures, const t_16bit *map)
{
	dbg_map((t_16bit*)map);
	printf("=== TRYYYY ===\n\n");
	return (!(*(const t_64bit*)(map - figures->y) & figures->value >> figures->x));
}

int					ft_solve(t_etr *figures, t_16bit *map, int sqr_size)
{
	int tmp;

	if (!figures->id)
		return (1);
	tmp = figures->prew ? 
		(figures->prew->x + figures->prew->y * sqr_size) : 0;
	figures->y = tmp / sqr_size;
	while (figures->y + figures->h <= sqr_size)
	{
		figures->x = (figures->y == tmp / sqr_size ? tmp % sqr_size : 0);
		while (figures->x + figures->w <= sqr_size)
		{
			if (ft_try_to_fill(figures, map))
			{
				ft_switch_figure(figures, map);
				if (ft_solve(figures + 1, map, sqr_size))
					return (1);
				ft_switch_figure(figures, map);
			}
			figures->x++;
		}
		figures->y++;
	}
	figures->x = 0;
	figures->y = 0;
	return (0);
}

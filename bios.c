/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bios.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:34:21 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/13 21:16:49 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tetrlst(int fd, t_list **tetrlst)
{
	char 	tmp[20];
	int		amount;

	tetrlst = NULL;
	if (21 != read(fd, tmp, 20))
		ft_error();
	if (1)

}

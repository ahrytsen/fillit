/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bios.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:34:21 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/16 19:11:09 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_tetrlst(int fd, t_list **tetriminos)
{
	char    **tetrimino;
	char    tmp[22];
	int     count;
	int		i;

	i = 0;
	ft_bzero(tmp, 22);
	while ((count = read(fd, tmp, 21)))
	{
		if ((count != 20 && count != 21) || i++ > 25
			|| !(tetrimino = ft_strsplit(tmp, '\n'))
			|| !ft_lstpush_back(tetriminos, tetrimino, 5 * sizeof(char*)))
			ft_error();
		free(tetrimino);
		ft_bzero(tmp, 22);
	}
	if (!*tetriminos)
		ft_error();
	return (*tetriminos);
}

void	ft_print_dbg(t_list **tetriminos)
{
	char **tmp;

	while (*tetriminos)
	{
		tmp = (*tetriminos)->content;
		while(*tmp)
			ft_putendl(*tmp++);
		ft_putchar('\n');
		tetriminos = &(*tetriminos)->next;
	}
}

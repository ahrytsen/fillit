/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:26:53 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/16 20:20:32 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

extern size_t	g_valid_form[19];

typedef struct	s_tetrimino
{
	char			id;
	unsigned char	x;
	unsigned char	y;
	unsigned char	width;
	unsigned char	heigh;
	unsigned long	form;
}				t_etrimino;

void			ft_error();
void			ft_usage();
void			ft_tetrlst(int fd, t_list **tetriminos);
void			ft_print_dbg(t_list *tetriminos);

#endif

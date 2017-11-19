/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:26:53 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/19 16:34:49 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef unsigned short	bit16;
typedef	unsigned long	bit64;
typedef struct s_map	t_map;
struct	s_map
{
	char	id;
	bit16	map[16];
	t_map	*next;
	t_map	*prew;
};

void			ft_error();
void			ft_usage();
void			ft_tetrlst(int fd, t_list **tetriminos);
void			ft_print_dbg(t_list *tetriminos);

#endif

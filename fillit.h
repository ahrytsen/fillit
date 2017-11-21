/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:26:53 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/21 17:22:56 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef unsigned char  t_8bit;
typedef unsigned short	t_16bit;
typedef	unsigned long	t_64bit;
typedef struct s_etr	t_etr;

struct					s_etr
{
	char	id;
	t_8bit	x;
	t_8bit  y;
	t_8bit  h;
    t_8bit  w;
	t_64bit	value;
	t_etr	*prew;
};

void					ft_error();
void					ft_usage();
void					ft_validate(char *tetr);
int						ft_reader(int fd, t_etr *figures);

void					ft_output(t_etr *figures, int size);

#endif

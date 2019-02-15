/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 14:54:24 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 15:16:12 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9999
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_stock
{
	char			*str;
	int				fd;
	struct s_stock	*next;
}					t_stock;

int					get_next_line(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 14:52:22 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 11:58:21 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_bresenham
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_bresen;

typedef struct	s_env
{
	int			i;
	int			j;
	int			len;
	int			spc;
	int			len_x;
	int			len_y;
	int			dec;
	int			base_x;
	int			base_y;
	int			z;
}				t_env;

typedef struct	s_graf
{
	void		*mlx;
	void		*win;
}				t_graf;

void			ft_bresen(t_point a, t_point b, void *mlx, void *win);
void			trace_line2(t_env size, int **fdf, int i, t_graf lol);
void			trace_column2(t_env size, int **fdf, int i, t_graf lol);

int				**read_stock(int fd, char *line, char **argv, t_graf *lol);
int				**read_stock2(int fd, char *line, int **fdf, t_env *size);
int				count(int **fdf);
int				trace_line(t_env size, int **fdf, t_graf lol);
int				trace_column(t_env size, int **fdf, t_graf lol);
int				hook_keydown(int key, void *mlx);
void			free_fdf(int **fdf, t_env size);

t_bresen		ft_init_bresen(t_point a, t_point b);
t_env			ft_init_env(t_env size);

#endif

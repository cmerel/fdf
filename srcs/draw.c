/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 14:58:26 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 12:25:16 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_env	ft_init_env(t_env size)
{
	if (size.len_y * size.len_x >= 10000)
	{
		size.base_x = 20;
		size.base_y = 1000;
		size.dec = 3;
	}
	else if (size.len_y * size.len_x < 500)
	{
		size.base_x = 500;
		size.base_y = 500;
		size.dec = 30;
	}
	else
	{
		size.base_x = 550;
		size.base_y = 600;
		size.dec = 11;
	}
	size.spc = 5;
	size.z = 0;
	return (size);
}

void	trace_column2(t_env size, int **fdf, int i, t_graf lol)
{
	t_point	a;
	t_point	b;
	int		j;

	j = 0;
	while (j < size.len_x - 1)
	{
		if (fdf[i][j] != 0 && j < size.len_x && i < size.len_y)
			size.z = fdf[i][j] * 1;
		else
			size.z = 0;
		a.y = (size.base_y - (j * size.spc) + (i * size.dec) - size.z);
		a.x = (size.base_x + (j * size.spc) + (j * size.dec));
		j++;
		if (fdf[i][j] != 0 && j < size.len_x && i < size.len_y)
			size.z = fdf[i][j] * 1;
		else
			size.z = 0;
		b.y = (size.base_y - (j * size.spc) + (i * size.dec) - size.z);
		b.x = (size.base_x + (j * size.spc) + (j * size.dec));
		ft_bresen(a, b, lol.mlx, lol.win);
	}
}

int		trace_column(t_env size, int **fdf, t_graf lol)
{
	int		i;

	i = 0;
	while (i < size.len_y)
	{
		trace_column2(size, fdf, i, lol);
		i++;
	}
	return (0);
}

void	trace_line2(t_env size, int **fdf, int i, t_graf lol)
{
	t_point	a;
	t_point	b;
	int		j;

	j = 0;
	while (j < size.len_x)
	{
		if (i < size.len_y && fdf[i][j] != 0 && j < size.len_x)
			size.z = fdf[i][j] * 1;
		else
			size.z = 0;
		a.y = (size.base_y - (j * size.spc) + (i * size.dec) - size.z);
		a.x = (size.base_x + (j * size.spc) + (j * size.dec));
		i++;
		if (i < size.len_y && fdf[i][j] != 0 && j < size.len_x)
			size.z = fdf[i][j] * 1;
		else
			size.z = 0;
		b.y = (size.base_y - (j * size.spc) + (i * size.dec) - size.z);
		b.x = (size.base_x + (j * size.spc) + (j * size.dec));
		ft_bresen(a, b, lol.mlx, lol.win);
		i--;
		j++;
	}
	i++;
}

int		trace_line(t_env size, int **fdf, t_graf lol)
{
	int		i;

	i = 0;
	while (i < size.len_y - 1)
	{
		trace_line2(size, fdf, i, lol);
		i++;
	}
	return (0);
}

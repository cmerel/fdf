/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 14:57:44 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 11:59:14 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void		free_fdf(int **fdf, t_env size)
{
	int		i;

	i = 0;
	while (i < size.len_y)
	{
		free(fdf[i]);
		i++;
	}
	free(fdf);
}

int			**read_stock(int fd, char *line, char **argv, t_graf *lol)
{
	int		**fdf;
	t_env	size;

	size.len = 0;
	while (get_next_line(fd, &line))
	{
		size.len++;
		free(line);
	}
	ft_strdel(&line);
	size.len_y = size.len;
	if (!(fdf = (int **)malloc(sizeof(int *) * size.len)))
		return (0);
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	fdf = read_stock2(fd, line, fdf, &size);
	size = ft_init_env(size);
	trace_column(size, fdf, *lol);
	trace_line(size, fdf, *lol);
	free_fdf(fdf, size);
	return (0);
}

int			**read_stock2(int fd, char *line, int **fdf, t_env *size)
{
	char	**split;

	size->i = 0;
	while (get_next_line(fd, &line))
	{
		size->j = 0;
		size->len = 0;
		split = ft_strsplit(line, ' ');
		free(line);
		while (split[size->len] != '\0')
			size->len++;
		if (!(fdf[size->i] = (int *)malloc(sizeof(int) * size->len)))
			return (0);
		size->len_x = size->len;
		while (size->j < size->len)
		{
			fdf[size->i][size->j] = ft_atoi(split[size->j]);
			size->j++;
		}
		ft_free_tab(split);
		size->i++;
	}
	ft_strdel(&line);
	return (fdf);
}

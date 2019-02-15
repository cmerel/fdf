/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 14:58:59 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 11:46:23 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int		hook_keydown(int key, void *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		main(int argc, char **argv)
{
	t_graf	lol;
	int		fd;
	char	*line;

	line = NULL;
	lol.mlx = mlx_init();
	lol.win = mlx_new_window(lol.mlx, 1650, 1350, "test");
	if (argc < 2 && argc > 5)
	{
		ft_putstr("usage: ./Fdf source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	read_stock(fd, line, argv, &lol);
	mlx_key_hook(lol.win, hook_keydown, (void*)0);
	mlx_loop(lol.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:17 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/22 14:01:24 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Helper function draw_line will draw the lines in the 2D map.
*/

void	draw_line(t_fractol *f, int i, int j, int k)
{
	if (i + 1 == f->rowlen - 1 && j + 1 < f->rows)
		mlx_pixel_put(f->mlx, f->win, f->a + f->scalex, f->b + k,
			get_color(ft_atoi(f->nbrs[j][i]), ft_atoi(f->nbrs[j + 1][i])));
	if (i - 1 >= 0)
		mlx_pixel_put(f->mlx, f->win, f->a - k, f->b,
			get_color(ft_atoi(f->nbrs[j][i]), ft_atoi(f->nbrs[j][i - 1])));
	if (i != f->rowlen - 1)
		mlx_pixel_put(f->mlx, f->win, f->a + k, f->b,
			get_color(ft_atoi(f->nbrs[j][i]), ft_atoi(f->nbrs[j][i + 1])));
	if (j + 1 != f->rows)
		mlx_pixel_put(f->mlx, f->win, f->a, f->b + k,
			get_color(ft_atoi(f->nbrs[j][i]), ft_atoi(f->nbrs[j + 1][i])));
	if (j - 1 >= 0)
		mlx_pixel_put(f->mlx, f->win, f->a, f->b - k,
			get_color(ft_atoi(f->nbrs[j][i]), ft_atoi(f->nbrs[j - 1][i])));
}

/*
**	Draw_twod will draw the f in 2D (parallel projection).
*/

void	draw_twod(t_fractol *f)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	while (++j < f->rows)
	{
		i = -1;
		while (++i < f->rowlen - 1)
		{
			k = -1;
			while (++k < f->scalex)
				draw_line(f, i, j, k);
			f->a += f->scalex;
		}
		f->a = f->startx;
		f->b += f->scaley;
	}
}

/*
**	Save_nbrs will read the lines in the file passed to the
**	program and save the strings of numbers into a 3D array
**	called f->nbrs with the help of ft_strsplit. Also calculates
**	the length of the rows and the amount of rows.
*/

int		save_nbrs(t_fractol *f, int *fd)
{
	char	*line;

	if (!(f->nbrs = (char ***)malloc(sizeof(char **) * 100000 + 1)))
		return (0);
	f->rows = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		f->nbrs[f->rows++] = ft_strsplit(line, ' ');
		ft_memdel((void **)&line);
	}
	f->nbrs[f->rows] = NULL;
	f->rowlen = 0;
	while (f->nbrs[0][f->rowlen])
		f->rowlen++;
	return (1);
}

int		save_input(char *av, t_fractol *f)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(save_nbrs(f, &fd)))
		return (0);
	close(fd);
	return (1);
}

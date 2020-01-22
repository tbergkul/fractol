/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:19:08 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/22 14:08:43 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*f;

	system("clear");
	if (ac != 2)
	{
		ft_putendl("\nusage: ./fractol input_file\n");
		ft_putendl("Available parameters:\n-> Julia\n-> Mandelbrot\n-> Ted\n");
		exit(1);
	}
	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (!(save_input(av[1], f)))
		return (-1);
	if (!(window(f)))
		return (-1);
	return (0);
}

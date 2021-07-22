/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:05:32 by user42            #+#    #+#             */
/*   Updated: 2021/07/22 15:34:43 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_fractal(t_data *data)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (data->fractal == 1)
				color = mand(data, -1.5 + (float)i * 3
						/ (WIDTH - 1), -((1.5) - (float)j * 3 / (HEIGHT - 1)));
			else if (data->fractal == 2)
				color = jul(data, -1.5 + (float)i * 3
						/ (WIDTH - 1), -((1.5) - (float)j * 3 / (HEIGHT - 1)));
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac == 1)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	init_mlx(data);
	if (init_fractal(data, av[1]))
		return (0);
	run_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	set_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}

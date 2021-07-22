/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:05:data->canvas2 by user42            #+#    #+#             */
/*   Updated: 2021/07/22 18:57:51 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_fractal(t_data *data)
{
	int	i;
	int	j;
	int	color;
	if (data->fractal == 1)
	{
	printf ("data->corner[X] = %f\n", data->corner[X]);
		data->corner[X] -= 0.55;
	printf ("data->corner[X] = %f\n", data->corner[X]);
		data->center[X] -= 0.55;
	}
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (data->fractal == 1)
			{
				color = mand(data, data->corner[X] + (float)i * data->canvas
						/ (WIDTH), -(data->corner[Y] - (float)j * data->canvas / (HEIGHT)));
			}
			else if (data->fractal == 2)
				color = jul(data, data->corner[X] + (float)i * data->canvas
						/ (WIDTH), -((data->corner[Y]) - (float)j * data->canvas / (HEIGHT)));
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

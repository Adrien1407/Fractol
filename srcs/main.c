/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienlancelle <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:30:00 by adrienlan         #+#    #+#             */
/*   Updated: 2021/07/29 16:16:39 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	run_fractal_loop(t_data *data)
{
	float	i;
	float	j;
	int		color;

	j = 0;
	while (j++ < HEIGHT)
	{
		i = 0;
		while (i++ < WIDTH)
		{
			if (data->fractal == 1)
			{
				color = mand(data, data->corner[X] + i * data->canvas / (WIDTH),
						-(data->corner[Y] - j * data->canvas / (HEIGHT)));
			}
			else if (data->fractal == 2)
				color = jul(data, data->corner[X] + i * data->canvas / (WIDTH),
						-((data->corner[Y]) - j * data->canvas / (HEIGHT)));
			my_mlx_pixel_put(data, i, j, color);
		}
	}
}

static void	run_fractal(t_data *data)
{
	if (data->fractal == 1)
	{
		data->corner[X] -= 0.55;
		data->center[X] -= 0.55;
	}
	run_fractal_loop(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (init_fractal(data, av[1]))
		init_mlx(data);
	else
	{
		printf("The argument must be \"julia\" or \"mandelbrot\"\n");
		free(data);
		return (0);
	}
	run_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	set_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}

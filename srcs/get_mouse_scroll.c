/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_scroll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienlancelle <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:24:59 by adrienlan         #+#    #+#             */
/*   Updated: 2021/07/23 19:26:58 by adrienlan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	zoom_in(t_data *data)
{
	data->canvas *= 0.9;
	data->corner[X] = data->center[X] - (data->canvas * 0.5);
	data->corner[Y] = data->center[Y] + (data->canvas * 0.5);
}

static void	zoom_out(t_data *data)
{
	data->canvas *= 1.1;
	data->corner[X] = data->center[X] - (data->canvas * 0.5);
	data->corner[Y] = data->center[Y] + (data->canvas * 0.5);
}

static void	zoom(int key, t_data *data)
{
	if (key == 5)
		zoom_in(data);
	if (key == 4)
		zoom_out(data);
}

int	get_mouse_scroll(int key, int x, int y, t_data *data)
{
	float	j;
	float	i;
	int		c;

	(void)x, (void)y;
	j = 0;
	if (key == 4 || key == 5)
		zoom(key, data);
	while (j++ < HEIGHT)
	{
		i = 0;
		while (i++ < WIDTH)
		{
			if (data->fractal == 1)
				c = mand(data, data->corner[X] + i * data->canvas / (WIDTH),
						-(data->corner[Y] - j * data->canvas / (HEIGHT)));
			else if (data->fractal == 2)
				c = jul(data, data->corner[X] + i * data->canvas
						/ (WIDTH), -((data->corner[Y]) - j * data->canvas
							/ (HEIGHT)));
			my_mlx_pixel_put(data, (int)i, (int)j, c);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

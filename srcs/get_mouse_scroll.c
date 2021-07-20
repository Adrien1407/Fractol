/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_scroll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:44:31 by adlancel          #+#    #+#             */
/*   Updated: 2021/07/20 18:23:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_mouse_scroll(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	int j;
	int i;
	int color;

	if (key == 5)
		data->zoom += 0.1;
	else if (key == 4)
		data->zoom -= 0.1;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			color = mandelbrot_magic((-1.5 * data->zoom) + (float)i * (3 * data->zoom) / (WIDTH - 1), (1.5 * data->zoom)-(float)j * (3 * data->zoom) / (HEIGHT - 1));
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
        mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

	return (1);
}

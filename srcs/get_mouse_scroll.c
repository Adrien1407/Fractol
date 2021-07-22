/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_scroll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:44:31 by adlancel          #+#    #+#             */
/*   Updated: 2021/07/22 15:33:06 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_zoom(t_data *data, int key)
{
	if (key == 5)
		data->zoom += 0.05;
	else if (key == 4)
		data->zoom -= 0.05;
}

int	get_mouse_scroll(int key, int x, int y, t_data *data)
{
	float	j;
	float	i;
	int		c;

	(void)x, (void)y;
	set_zoom(data, key);
	j = 0;
	while (j++ < HEIGHT)
	{
		i = 0;
		while (i++ < WIDTH)
		{
			if (data->fractal == 1)
				c = mand(data, ((-1.5 + i * (3 * data->zoom) / (WIDTH - 1))
							* data->zoom), ((1.5 - j * (3 * data->zoom)
								/ (HEIGHT - 1)) * data->zoom));
			else if (data->fractal == 2)
				c = jul(data, (-1.5 * data->zoom) + i * (3 * data->zoom)
						/ (WIDTH - 1), (1.5 * data->zoom) - j
						* (3 * data->zoom) / (HEIGHT - 1));
			my_mlx_pixel_put(data, (int)i, (int)j, c);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_scroll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:44:data->canvas1 by adlancel          #+#    #+#             */
/*   Updated: 2021/07/22 18:59:09 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data)
{
//printf("data->corner[X] =%f\n ", data->corner[X]);
	data->canvas *= 0.9;
	data->corner[X] = data->center[X] - (data->canvas * 0.5) ;
	data->corner[Y] = data->center[Y] + (data->canvas * 0.5) ;
}
void	zoom_out(t_data *data)
{
	data->canvas *= 1.1;
	data->corner[X] = data->center[X] - (data->canvas * 0.5) ;
	data->corner[Y] = data->center[Y] + (data->canvas * 0.5) ;
}
void	zoom(int key, t_data *data)
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
			c = mand(data, data->corner[X] + (float)i * data->canvas
						/ (WIDTH), -(data->corner[Y] - (float)j * data->canvas / (HEIGHT)));
			else if (data->fractal == 2)
			c = jul(data, data->corner[X] + (float)i * data->canvas
						/ (WIDTH), -((data->corner[Y]) - (float)j * data->canvas / (HEIGHT)));
			my_mlx_pixel_put(data, (int)i, (int)j, c);
		}
	}
	//printf("data->center[X] =%f\ndata->center[Y]=%f\ndata->corner[X]=%f\ndata->corner[Y]=%f\n", data->center[X], data->center[Y], data->corner[X], data->corner[Y]);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

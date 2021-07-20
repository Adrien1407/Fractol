/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:05:32 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 18:09:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     main(int ac, char **av)
{
        int color;
        int i;
        int j;
        t_data *data;

        data = NULL;
        if (ac != 2)
                return (0);
        if (init_fractal(av[1]))
                return (0);
        data = malloc(sizeof(t_data));
        if (!data)
                return (0);
        init_mlx(data);
        data->zoom = 1;
		j = 0;
        while (j < HEIGHT)
        {
                i = 0;
                while (i < WIDTH)
                {
                        color = mandelbrot_magic(-1.5 + (float)i * 3 / (WIDTH - 1), (1.5)-(float)j * 3  / (HEIGHT - 1));
                        my_mlx_pixel_put(data, i, j, color);
                        i++;
                }
                j++;
        }

        mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
        set_hooks(data);
        mlx_loop(data->mlx);
        return (0);
}


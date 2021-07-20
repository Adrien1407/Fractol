/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:35:40 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 17:08:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_mlx(t_data *data)
{
        data->mlx = mlx_init();
        data->zoom = 1;
        data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
        data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
        data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:57 by user42            #+#    #+#             */
/*   Updated: 2021/07/26 19:04:33 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_fractal(t_data *data, char *str)
{
	if (ft_strncmp("mandelbrot", str, 10) == 0)
	{
		data->fractal = 1;
		return (1);
	}
	else if (ft_strncmp("julia", str, 5) == 0)
	{
		data->fractal = 2;
		return (1);
	}
	return (0);
}

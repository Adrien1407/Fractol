/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_magic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:33:54 by user42            #+#    #+#             */
/*   Updated: 2021/07/26 17:47:39 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mand(t_data *data, float x, float y)
{
	int		color;
	int		n;
	int		n_max;
	float	ret[2];
	float	tmp;

	ret[X] = 0;
	ret[Y] = 0;
	n_max = 1000;
	n = 0;
	while (((power_2(ret[X]) + power_2(ret[Y])) < 4) && (n < n_max))
	{
		tmp = ret[X];
		ret[X] = power_2(ret[X]) - power_2(ret[Y]) + x;
		ret[Y] = (2 * ret[Y] * tmp) + y;
		++n;
	}
	if (n == n_max)
		color = 0;
	else
		color = data->rgb[n % 32];
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:52:48 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/02 13:34:41 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	jul(t_data *data, float x, float y)
{
	int		n;
	int		n_max;
	float	tmp;
	float	cr;
	float	ci;

	cr = -0.4;
	ci = 0.6;
	n_max = 1000;
	n = 0;
	while (((power_2(x) + power_2(y)) < 4) && (n < n_max))
	{
		tmp = x;
		x = power_2(x) - power_2(y) + cr;
		y = 2 * y * tmp + ci;
		++n;
	}
	if (n == n_max)
		return (0);
	else
		return (data->rgb[n % 32]);
}

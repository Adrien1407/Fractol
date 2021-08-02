/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:45:41 by adlancel          #+#    #+#             */
/*   Updated: 2021/07/26 18:20:52 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	init_rgb_bis(t_data *data)
{
	data->rgb[16] = 0x306082;
	data->rgb[17] = 0x5b6ee1;
	data->rgb[18] = 0x639bff;
	data->rgb[19] = 0x5fcde4;
	data->rgb[20] = 0xcbdbfc;
	data->rgb[21] = 0xffffff;
	data->rgb[22] = 0x9badb7;
	data->rgb[23] = 0x847e87;
	data->rgb[24] = 0x696a6a;
	data->rgb[25] = 0x595652;
	data->rgb[26] = 0x76428a;
	data->rgb[27] = 0xac3232;
	data->rgb[28] = 0xd95763;
	data->rgb[29] = 0xd77bba;
	data->rgb[30] = 0x8f974a;
	data->rgb[31] = 0x8a6f30;
}

void	init_rgb(t_data *data)
{
	data->rgb[0] = 0x000000;
	data->rgb[1] = 0x222034;
	data->rgb[2] = 0x45283c;
	data->rgb[3] = 0x663931;
	data->rgb[4] = 0x8f563b;
	data->rgb[5] = 0xdf7126;
	data->rgb[6] = 0xd9a066;
	data->rgb[7] = 0xeec39a;
	data->rgb[8] = 0xfbf236;
	data->rgb[9] = 0x99e550;
	data->rgb[10] = 0x6abe30;
	data->rgb[11] = 0x37946e;
	data->rgb[12] = 0x4b692f;
	data->rgb[13] = 0x524b24;
	data->rgb[14] = 0x323c39;
	data->rgb[15] = 0x3f3f74;
	init_rgb_bis(data);
}

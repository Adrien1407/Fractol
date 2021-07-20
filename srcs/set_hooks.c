/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:35:22 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 17:02:39 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_hooks(t_data *data)
{

        mlx_hook(data->win, 2, 1L<<0, get_key_press, data);
        mlx_hook(data->win, 4, 4L<<0, get_mouse_scroll, data);
        mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
}


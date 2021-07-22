/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:29:25 by user42            #+#    #+#             */
/*   Updated: 2021/07/22 18:32:12 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define ECHAP 65307
# define HEIGHT 1000 
# define WIDTH 1000
# define TITLE "HELLO WORLD"
# define X 0
# define Y 1

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		rgb[16];
	int		fractal;
	float	corner[2];
	float	canvas;
	float	center[2];
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_and_free(t_data *data);
int		get_key_press(int key, t_data *data);
int		get_mouse_scroll(int key, int x, int y, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	init_mlx(t_data *data);
void	init_rgb(int *rgb);
void	set_hooks(t_data *data);
int		init_fractal(t_data *data, char *str);
float	power_2(float n);
int		mand(t_data *data, float x, float y);
int		jul(t_data *data, float x, float y);
int		main(int ac, char **av);
#endif

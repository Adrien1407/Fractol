/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:37:50 by adlancel          #+#    #+#             */
/*   Updated: 2021/07/20 14:46:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>


#define ECHAP 65307
#define HEIGHT 1000 
#define WIDTH 1000
#define TITLE "HELLO WORLD"
#define X 0
#define Y 1

typedef struct  s_data  {
        void    *img;
        void    *mlx;
        void    *win;
        char    *addr;
        int     bits_per_pixel;
        int     line_length;
        int     endian;
}               t_data;



static void     my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
        char    *dst;

        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

int     exit_and_free(t_data *data)
{
        mlx_destroy_image(data->mlx, data->img);
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        if (data->mlx)
                free(data->mlx);
        if (data)
                free(data);
        exit(1);
}

int     get_key_press(int key, t_data *data)
{
        if  (key == ECHAP)
                return (exit_and_free(data));

        return (1);
}


int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t  i;

        i = 0;
        if (n == 0)
                return (0);
        while ((s1[i] && s2[i] && s1[i] == s2[i]) && (i < n - 1))
                i++;
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
void    init_mlx(t_data *data)
{

        data->mlx = mlx_init();
        data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
        data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
        data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}
void    set_hooks(t_data *data)
{

        mlx_hook(data->win, 2, 1L<<0, get_key_press, data);
        mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
}
int     init_fractal(char *str)
{
        if (ft_strncmp("julia", str, 5) == 0)
                return (0);
        else if (ft_strncmp("mandelbrot", str, 10) == 0)
                return (0);
        return (1);
}
float   power_2(float n)
{
        return (n * n);
}

int     mandelbrot_magic(float x, float y)
{
        int color;
        int n;
        int n_max;
        float ret[2];
        float tmp;

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
                color  = 0;

        else
                color =  n * (16777215 / n_max) * 1500;
        return (color);
}
*/
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
        j = 0;
        while (j < HEIGHT)
        {
                i = 0;
                while (i < WIDTH)
                {
                        color = mandelbrot_magic(-3 + (float)i * 6 / (WIDTH - 1), 3 -(float)j * 6 / (HEIGHT - 1));
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


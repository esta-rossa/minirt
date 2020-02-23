/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:54:59 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:32:16 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

const double g_filter[FILTER_Y][FILTER_X] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 1}
};

static	int		ft_modulus(int a, int m)
{
	if (a > 0)
		return (a % m);
	return (a - (a % m));
}

static	void	filter_calc(int *image, t_color *color, int *indexs)
{
	indexs[4] = ft_modulus(indexs[0] - (FILTER_X / 2) +
	(indexs[3]), g_all->wind->wind_x);
	indexs[5] = ft_modulus(indexs[1] - (FILTER_Y / 2) +
	(indexs[2]), g_all->wind->wind_y);
	color[0] = get_color(image[((indexs[5] * (g_all->wind->wind_x)) +
	indexs[4])]);
	color[1].r += (color[0].r *
	g_filter[indexs[2]][indexs[3]] * (1.0 / 9.0)) / 255.0;
	color[1].g += (color[0].g *
	g_filter[indexs[2]][indexs[3]] * (1.0 / 9.0)) / 255.0;
	color[1].b += (color[0].b *
	g_filter[indexs[2]][indexs[3]] * (1.0 / 9.0)) / 255.0;
}

static	void	filter_loop(int *img, int *image, t_color *color, int *indexs)
{
	while (++indexs[0] < g_all->wind->wind_x)
	{
		indexs[1] = -1;
		while (++indexs[1] < g_all->wind->wind_y)
		{
			indexs[2] = -1;
			color[1] = (t_color){0, 0, 0};
			while (++indexs[2] < FILTER_Y)
			{
				indexs[3] = -1;
				while (++indexs[3] < FILTER_X)
				{
					filter_calc(image, color, indexs);
				}
			}
			img[(indexs[1] * g_all->wind->wind_x) +
			indexs[0]] = get_int(&color[1]);
		}
	}
}

void			filter(int *img)
{
	int		indexs[6];
	t_color	color[2];
	int		*image;

	if (!(image = malloc(sizeof(int) * g_all->wind->wind_x *
	g_all->wind->wind_y)))
		ft_exit(E_STD);
	image = ft_memcpy(image, img, sizeof(int) *
	g_all->wind->wind_x * g_all->wind->wind_y);
	indexs[0] = -1;
	filter_loop(img, image, color, indexs);
	free(image);
}

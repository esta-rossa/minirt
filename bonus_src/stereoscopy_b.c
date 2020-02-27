/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereoscopy_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:38:38 by arraji            #+#    #+#             */
/*   Updated: 2020/02/27 16:35:03 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	merge_iamges(int *orignal, int *copy)
{
	size_t	size;
	size_t	index;
	t_color	color[2];

	index = 0;
	size = g_all->wind->wind_x * g_all->wind->wind_y;
	while (index < size)
	{
		color[0] = get_color(orignal[index]);
		color[0] = color_mltp(color[0], (double)1 / 255);
		color[1] = get_color(copy[index]);
		color[1] = color_mltp(color[1], (double)1 / 255);
		color[0] = color_add(color[0], color[1]);
		orignal[index] = get_int(&color[0]);
		index++;
	}
	free(copy);
}

void			stereoscopy_render(t_all *all)
{
	int		*copy;
	t_cord	pos;

	all->str = 2;
	pos = all->a_camera->pos;
	if (!(copy = (int *)malloc(4 * all->wind->wind_x * all->wind->wind_y)))
		ft_exit(E_STD);
	all->a_camera->pos = vector_add(pos,
	vector_mltp(all->a_camera->right, -1));
	threads_parent();
	all->filter == 1 ? filter(all->wind->img_data) : 1;
	ft_memcpy(copy, all->wind->img_data, 4 *
	all->wind->wind_x * all->wind->wind_y);
	all->str = 1;
	all->a_camera->pos = vector_add(pos,
	vector_mltp(all->a_camera->right, 1));
	threads_parent();
	all->filter == 1 ? filter(all->wind->img_data) : 1;
	all->a_camera->pos = pos;
	merge_iamges(all->wind->img_data, copy);
}

static	void	gray_scale(t_color *color)
{
	double		light_scale;
	double		gray_scale;

	light_scale = (.2126 * color->r) +
		(0.7152 * color->g) + (0.0722 * color->b);
	if (light_scale <= 0.0031308)
		gray_scale = 12.92 * light_scale;
	else
		gray_scale = 1.055 * pow(light_scale, 1 / 2.4) - 0.055;
	*color = (t_color){gray_scale, gray_scale, gray_scale};
}

void			stereoscopy_filter(t_color *color, int type)
{
	if (type == 1)
	{
		gray_scale(color);
		color->g *= 0;
		color->b *= 0;
	}
	else if (type == 2)
	{
		gray_scale(color);
		color->r *= 0;
	}
}

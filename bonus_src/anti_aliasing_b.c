/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:43:48 by arraji            #+#    #+#             */
/*   Updated: 2020/02/22 07:14:39 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	t_color		average_color(t_color *color)
{
	t_color		new;

	new.r = (color[0].r + color[1].r + color[2].r + color[3].r) / 4;
	new.g = (color[0].g + color[1].g + color[2].g + color[3].g) / 4;
	new.b = (color[0].b + color[1].b + color[2].b + color[3].b) / 4;
	return (new);
}

void				get_all_rays(t_cord *v_rays, double x, double y)
{
	v_rays[0] = get_ray(*(g_all)->a_camera,
	g_all->a_camera->bot, x + 0.2, y + 0.3);
	v_rays[1] = get_ray(*(g_all)->a_camera,
	g_all->a_camera->bot, x + 0.3, y - 0.2);
	v_rays[2] = get_ray(*(g_all)->a_camera,
	g_all->a_camera->bot, x - 0.4, y + 0.3);
	v_rays[3] = get_ray(*(g_all)->a_camera,
	g_all->a_camera->bot, x - 0.2, y - 0.2);
}

void				render_all_ray(t_color *colors, t_cord *v_rays)
{
	render(*g_all, *g_all->a_camera, &colors[0], v_rays[0]);
	stereoscopy_filter(&colors[0], g_all->str);
	render(*g_all, *g_all->a_camera, &colors[1], v_rays[1]);
	stereoscopy_filter(&colors[1], g_all->str);
	render(*g_all, *g_all->a_camera, &colors[2], v_rays[2]);
	stereoscopy_filter(&colors[2], g_all->str);
	render(*g_all, *g_all->a_camera, &colors[3], v_rays[3]);
	stereoscopy_filter(&colors[3], g_all->str);
}

void				get_pixel(int *indexs, int *img)
{
	t_cord	v_rays[4];
	t_color colors[4];

	if (g_all->aa == 1)
	{
		get_all_rays(v_rays, indexs[1], indexs[0]);
		render_all_ray(colors, v_rays);
		colors[0] = average_color(colors);
		*img = get_int(&colors[0]);
	}
	else
	{
		v_rays[0] = get_ray(*(g_all)->a_camera,
		g_all->a_camera->bot, indexs[1], indexs[0]);
		render(*g_all, *g_all->a_camera, &colors[0], v_rays[0]);
		stereoscopy_filter(&colors[0], g_all->str);
		*img = get_int(&colors[0]);
	}
}

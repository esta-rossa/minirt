/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:43:48 by arraji            #+#    #+#             */
/*   Updated: 2020/02/12 02:56:47 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void		get_all_rays(t_cord *v_rays, double x, double y)
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

void		render_all_ray(t_color *colors, t_cord *v_rays)
{
	render(*g_all, *g_all->a_camera, &colors[0], v_rays[0]);
	render(*g_all, *g_all->a_camera, &colors[1], v_rays[1]);
	render(*g_all, *g_all->a_camera, &colors[2], v_rays[2]);
	render(*g_all, *g_all->a_camera, &colors[3], v_rays[3]);
}

void		get_pixel(int *indexs, int *img)
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
		/* colors[0].r = colors[0].r * 0 + colors[0].g * 0.2 + colors[0].b * 0;
		colors[0].g = colors[0].r * 0.2 + colors[0].g * 0.2 + colors[0].b * 0.2;
		colors[0].b = colors[0].r * 0 + colors[0].g * 0.2 + colors[0].b * 0; */
		*img = get_int(&colors[0]);
	}
}

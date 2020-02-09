/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:43:48 by arraji            #+#    #+#             */
/*   Updated: 2020/02/08 23:46:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void		get_all_rays(t_cord *v_rays, double x, double y)
{
	v_rays[0] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x + 0.2 , y + 0.3);
	v_rays[1] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x + 0.3, y - 0.2);
	v_rays[2] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x - 0.4, y + 0.3);
	v_rays[3] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x - 0.2, y - 0.2);
}

void		render_all_ray(t_color *colors, t_cord *v_rays)
{
	render(*all_save, *all_save->a_camera, &colors[0], v_rays[0]);
	render(*all_save, *all_save->a_camera, &colors[1], v_rays[1]);
	render(*all_save, *all_save->a_camera, &colors[2], v_rays[2]);
	render(*all_save, *all_save->a_camera, &colors[3], v_rays[3]);
}

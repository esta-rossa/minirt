/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:44:32 by arraji            #+#    #+#             */
/*   Updated: 2020/01/06 15:47:10 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_camera(t_camera *camera, t_all all)
{
	t_cord	middle;
	t_cord	view_ray;
	double	width_unit;
	double	height_unit;
	t_cord	bot_left;

	camera->l_at.x += 0.0001;
	camera->x_reso = all.wind->wind_x;
	camera->y_reso = all.wind->wind_y;
	middle = vector_add(camera->pos, camera->l_at);
	pr_cord(middle, "midlle", "\n");
	view_ray = vector_sub(middle, camera->pos);
	camera->right = vector_norm(cross_prod(new_cord(0, 1, 0), view_ray));
	camera->up = vector_norm(cross_prod(camera->right, view_ray));
	width_unit = tan(deg_to_rad(camera->fov) / 2);
	height_unit = ((double)camera->y_reso / camera->x_reso) * width_unit;
	bot_left = vector_add(middle, vector_mltp(camera->up, -height_unit));
	bot_left = vector_add(bot_left, vector_mltp(camera->right, -width_unit));
	camera->x_inc = vector_div(vector_mltp(camera->right, 2 * width_unit)
	, camera->x_reso);
	camera->y_inc = vector_div(vector_mltp(camera->up, 2 * height_unit)
	, camera->y_reso);
	camera->bot = bot_left;
}

t_cord	get_ray(t_camera camera, t_cord bo_left, double x, double y)
{
	t_cord		curr;
	t_cord		ray;

	curr = vector_add(bo_left, vector_mltp(camera.x_inc, x));
	curr = vector_add(curr, vector_mltp(camera.y_inc, y));
	ray = vector_sub(curr, camera.pos);

	return (ray);
}

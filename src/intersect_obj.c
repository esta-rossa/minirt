/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:27:53 by arraji            #+#    #+#             */
/*   Updated: 2020/01/16 23:11:04 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		sp_inters(t_obj o, t_camera camera, double *t)
{
	double	new_t;

	o.a = dot_pr(camera.v_ray, camera.v_ray);
	o.b = (dot_pr(camera.pos, camera.v_ray)
	- dot_pr(o.pos, camera.v_ray)) * 2;
	o.c = dot_pr(o.pos, o.pos)
	- (o.radius * o.radius)
	- (2 * dot_pr(o.pos, camera.pos))
	+ dot_pr(camera.pos, camera.pos);
	o.delta = o.b * o.b - 4 * o.a * o.c;
	if (o.delta > 0)
	{
		o.delta = sqrt(o.delta);
		new_t = (((-o.b + o.delta) / (2 * o.a)) < ((-o.b - o.delta) / (2 * o.a))
		? ((-o.b + o.delta) / (2 * o.a)) : ((-o.b - o.delta) / (2 * o.a)));
		if (new_t > 0 && new_t <= *t && new_t > NEAR)
		{
			*t = new_t;
			return (1);
		}
	}
	return (0);
}

int		plan_inters(t_obj o, t_camera camera, double *t)
{
	double	new_t;

	if (dot_pr(camera.v_ray, o.norm) != 0)
	{
		new_t = (-dot_pr(vector_sub(camera.pos, o.pos), o.norm))
		/ dot_pr(camera.v_ray, o.norm);
		if (new_t > 0 && new_t <= *t && new_t > NEAR)
		{
			*t = new_t;
			return (1);
		}
	}
	return (0);
}

int		inters(t_obj *obj, t_camera camera, double *t)
{
	double	t_tmp;
	int		inter;
	int		index;
	int		pos;

	pos = 0;
	index = 0;
	t_tmp = *t;
	inter = 0;
	while (obj)
	{
		if (obj->type == SPHERE)
			if (sp_inters(*obj, camera, &t_tmp))
			{
				inter = 1;
				pos = index;
			}
		if (obj->type == PLANE)
			if (plan_inters(*obj, camera, &t_tmp))
			{
				inter = 1;
				pos = index;
			}
		if (obj->type == CYLINDER)
			if (cyl_inters(obj, camera, &t_tmp))
			{
				inter = 1;
				pos = index;
			}
		if (obj->type == TRIANGLE)
			if (triangle_inters(obj, camera, &t_tmp))
			{
				inter = 1;
				pos = index;
			}
		index++;
		obj = obj->next;
	}
	*t = t_tmp;
	return (inter == 1 ? pos : -1);
}

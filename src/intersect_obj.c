/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:27:53 by arraji            #+#    #+#             */
/*   Updated: 2020/02/02 22:36:38 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		sp_inters(t_obj *o, t_camera camera, double *t)
{
	double	new_t[2];

	o->a = dot_pr(camera.v_ray, camera.v_ray);
	o->b = (dot_pr(camera.pos, camera.v_ray)
	- dot_pr(o->pos, camera.v_ray)) * 2;
	o->c = dot_pr(o->pos, o->pos)
	- (o->radius * o->radius)
	- (2 * dot_pr(o->pos, camera.pos))
	+ dot_pr(camera.pos, camera.pos);
	o->delta = o->b * o->b - 4 * o->a * o->c;
	if (o->delta > 0)
	{
		o->delta = sqrt(o->delta);
		new_t[0] = (-o->b + o->delta) / (2 * o->a);
		new_t[1] = (-o->b - o->delta) / (2 * o->a);
		smallest_double(new_t, 2);
		if (new_t[0] > 0 && new_t[0] <= *t && new_t[0] > NEAR)
		{
			*t = new_t[0];
			return (1);
		}
	}
	return (0);
}

int		plan_inters(t_obj *o, t_camera camera, double *t)
{
	double	new_t;

	if (dot_pr(camera.v_ray, o->norm) != 0)
	{
		new_t = (-dot_pr(vector_sub(camera.pos, o->pos), o->norm))
		/ dot_pr(camera.v_ray, o->norm);
		if (new_t > 0 && new_t <= *t && new_t > NEAR)
		{
			*t = new_t;
			return (1);
		}
	}
	return (0);
}

void	assign_functions(
int (*inter_funs[5])(t_obj *o, t_camera camera, double *t))
{
	inter_funs[0] = plan_inters;
	inter_funs[1] = sp_inters;
	inter_funs[2] = cyl_inters;
	inter_funs[3] = squar_inters;
	inter_funs[4] = triangle_inters;
}

int		inters(t_obj *obj, t_camera camera, double *t)
{
	double	t_tmp;
	int		index;
	int		pos;
	int		(*inter_funs[5])(t_obj *o, t_camera camera, double *t);

	pos = -1;
	index = 0;
	t_tmp = *t;
	assign_functions(inter_funs);
	while (obj)
	{
		if (inter_funs[obj->type - 1](obj, camera, &t_tmp))
			pos = index;
		index++;
		obj = obj->next;
	}
	*t = t_tmp;
	return (pos);
}

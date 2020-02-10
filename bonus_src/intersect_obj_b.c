/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:27:53 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 17:34:16 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

int				sp_inters(t_obj *o, t_camera camera, double *t)
{
	double	new_t[2];
	double	vars[4];

	vars[1] = dot_pr(camera.v_ray, camera.v_ray);
	vars[2] = (dot_pr(camera.pos, camera.v_ray)
	- dot_pr(o->pos, camera.v_ray)) * 2;
	vars[3] = dot_pr(o->pos, o->pos)
	- (o->radius * o->radius)
	- (2 * dot_pr(o->pos, camera.pos))
	+ dot_pr(camera.pos, camera.pos);
	vars[0] = (vars[2] * vars[2]) - (4 * vars[1] * vars[3]);
	if (vars[0] > 0)
	{
		vars[0] = sqrt(vars[0]);
		new_t[0] = (-vars[2] + vars[0]) / (2 * vars[1]);
		new_t[1] = (-vars[2] - vars[0]) / (2 * vars[1]);
		smallest_double(new_t, 2);
		if (new_t[0] > 0 && new_t[0] < *t && new_t[0] > NEAR)
		{
			*t = new_t[0];
			return (1);
		}
	}
	return (0);
}

int				plan_inters(t_obj *o, t_camera camera, double *t)
{
	double	new_t;

	if (dot_pr(camera.v_ray, o->norm) != 0)
	{
		new_t = (-dot_pr(vector_sub(camera.pos, o->pos), o->norm))
		/ dot_pr(camera.v_ray, o->norm);
		if (new_t > 0 && new_t < *t && new_t > NEAR)
		{
			*t = new_t;
			return (1);
		}
	}
	return (0);
}

static	void	assign_functions(
int (*inter_funs[6])(t_obj *o, t_camera camera, double *t))
{
	inter_funs[0] = plan_inters;
	inter_funs[1] = sp_inters;
	inter_funs[2] = cyl_inters;
	inter_funs[3] = squar_inters;
	inter_funs[4] = triangle_inters;
	inter_funs[5] = disk_inters;
}

int				inters(t_obj *obj, t_camera camera, double *t)
{
	double	t_tmp;
	int		index;
	int		pos;
	int		(*inter_funs[6])(t_obj *o, t_camera camera, double *t);

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

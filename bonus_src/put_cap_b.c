/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 04:11:53 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 12:34:05 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

int		disk_inters(t_obj *o, t_camera camera, double *t)
{
	double	save;
	t_cord	p;
	t_cord	vec;
	double	dis;

	save = *t;
	if (plan_inters(o, camera, &save))
	{
		p = vector_add(camera.pos, vector_mltp(camera.v_ray, save));
		vec = vector_sub(p, o->pos);
		dis = sqrt(dot_pr(vec, vec));
		if (dis <= o->diam / 2)
		{
			*t = save;
			return (1);
		}
	}
	return (0);
}

void	put_cap(t_obj *o, t_camera camera, double *t)
{
	t_obj	up_plan;
	t_obj	down_plan;

	o->cap = 1;
	down_plan.pos = o->pos;
	down_plan.norm = o->orient;
	down_plan.diam = o->diam;
	up_plan.pos = vector_add(o->pos, vector_mltp(o->orient, o->height));
	up_plan.norm = o->orient;
	up_plan.diam = o->diam;
	if (disk_inters(&down_plan, camera, t))
		o->cap = -1;
	if (disk_inters(&up_plan, camera, t))
		o->cap = -1;
}

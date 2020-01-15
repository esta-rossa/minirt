/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:30:41 by arraji            #+#    #+#             */
/*   Updated: 2020/01/14 22:20:47 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		cyl_inters_init(t_obj *o, t_camera camera, t_cyl_needs *need)
{
	t_cord cam_ori;

	need->t[0] = FAR;
	need->t[1] = FAR;
	cam_ori = vector_sub(camera.pos, o->pos);
	o->a = dot_pr(camera.v_ray, camera.v_ray) -
	dot_pr(camera.v_ray, o->orient) * dot_pr(camera.v_ray, o->orient);
	o->b = (dot_pr(camera.v_ray, cam_ori) - (dot_pr(camera.v_ray, o->orient)
	* dot_pr(cam_ori, o->orient))) * 2;
	o->c = dot_pr(cam_ori, cam_ori) - (dot_pr(cam_ori, o->orient)
	* dot_pr(cam_ori, o->orient)) - (o->diam / 2) * (o->diam / 2);
	o->delta = o->b * o->b - 4 * o->a * o->c;
	o->delta = sqrt(o->delta);
	if (o->delta > 0)
		return (1);
	return (0);
}

int		disk_iners(t_obj o, t_camera camera, double *t)
{
	double	save;
	t_cord	p;
	t_cord	vec;
	double	dis;

	save = *t;
	if (plan_inters(o, camera, &save))
	{
		p = vector_add(camera.pos, vector_mltp(camera.v_ray, save));
		vec = vector_sub(p, o.pos);
		dis = sqrt(dot_pr(vec, vec));
		if (dis <= o.diam / 2)
		{
			*t = save;
			return (1);
		}
	}
	return (0);
}

int		cyl_inters(t_obj *o, t_camera camera, double *t)
{
	t_cyl_needs		need;
	double			new_t;

	new_t = *t;
	if (cyl_inters_init(o, camera, &need))
	{
		cyl_calcul(o, camera, &need);
		if (need.m[0] > 0 && need.m[0] < o->height)
		{
			new_t = need.t[0];
			cyl_norm(o, camera, need, 1);
		}
		else if (need.m[1] > 0 && need.m[1] < o->height)
		{
			new_t = need.t[1];
			cyl_norm(o, camera, need, -1);
		}
		put_cap(o, camera, &new_t);
		if (new_t > 0 && new_t < *t && new_t > NEAR)
		{
			*t = new_t;
			return (1);
		}
	}
	return (0);
}

void	cyl_norm(t_obj *o, t_camera camera, t_cyl_needs need, int dir)
{
	t_cord			p_inter;

	if (dir == 1)
	{
		p_inter = vector_add(camera.pos,
		vector_mltp(camera.v_ray, need.t[0]));
		o->norm = vector_norm(vector_sub(
		p_inter, vector_add(o->pos, vector_mltp(o->orient, need.m[0]))));
	}
	if (dir == -1)
	{
		p_inter = vector_add(camera.pos,
		vector_mltp(camera.v_ray, need.t[1]));
		o->norm = vector_norm(vector_sub(
			vector_add(o->pos, vector_mltp(o->orient, need.m[1])), p_inter));
	}
}

void	put_cap(t_obj *o, t_camera camera, double *t)
{
	t_obj	up_plan;
	t_obj	down_plan;

	if (o->cap != 0)
	{
		down_plan.pos = o->pos;
		down_plan.norm = o->orient;
		down_plan.diam = o->diam;
		up_plan.pos = vector_add(o->pos, vector_mltp(o->orient, o->height));
		up_plan.norm = o->orient;
		up_plan.diam = o->diam;
		if (disk_iners(down_plan, camera, t))
			o->norm = vector_mltp(o->orient, -1);
		if (disk_iners(up_plan, camera, t))
			o->norm = o->orient;
	}
}

void	cyl_calcul(t_obj *o, t_camera camera, t_cyl_needs *need)
{
	t_cord		cam_ori;

	cam_ori = vector_sub(camera.pos, o->pos);
	need->t[0] = (-o->b + o->delta) / (2 * o->a);
	need->t[1] = (-o->b - o->delta) / (2 * o->a);
	smallest_double(need->t, 2);
	need->m[0] = (dot_pr(camera.v_ray, o->orient)
	* need->t[0]) + dot_pr(cam_ori, o->orient);
	need->m[1] = (dot_pr(camera.v_ray, o->orient)
	* need->t[1]) + dot_pr(cam_ori, o->orient);
}

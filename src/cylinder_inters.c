/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:30:41 by arraji            #+#    #+#             */
/*   Updated: 2020/02/03 19:29:44 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	int		cyl_inters_init(t_obj *o, t_camera camera, t_cyl_needs *need)
{
	t_cord cam_ori;

	need->t[0] = FAR;
	need->t[1] = FAR;
	cam_ori = vector_sub(camera.pos, o->pos);
	o->a = dot_pr(camera.v_ray, camera.v_ray) -
	(dot_pr(camera.v_ray, o->orient) * dot_pr(camera.v_ray, o->orient));
	o->b = (dot_pr(camera.v_ray, cam_ori) - (dot_pr(camera.v_ray, o->orient)
	* dot_pr(cam_ori, o->orient))) * 2;
	o->c = dot_pr(cam_ori, cam_ori) - (dot_pr(cam_ori, o->orient)
	* dot_pr(cam_ori, o->orient)) - ((o->diam / 2) * (o->diam / 2));
	o->delta = (o->b * o->b) - (4 * o->a * o->c);
	o->delta = sqrt(o->delta);
	if (o->delta > 0)
		return (1);
	return (0);
}

static	void	cyl_calcul(t_obj *o, t_camera camera, t_cyl_needs *need)
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

int				cyl_inters(t_obj *o, t_camera camera, double *t)
{
	t_cyl_needs		need;
	double			new_t;

	new_t = *t;
	if (cyl_inters_init(o, camera, &need))
	{
		cyl_calcul(o, camera, &need);
		if (need.m[0] > 0 && need.m[0] < o->height)
			new_t = need.t[0];
		else if (need.m[1] > 0 && need.m[1] < o->height)
			new_t = need.t[1];
		if (new_t > 0 && new_t < *t && new_t > NEAR)
		{
			*t = new_t;
			return (1);
		}
	}
	return (0);
}

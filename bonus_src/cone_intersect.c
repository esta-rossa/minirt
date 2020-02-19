/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:35:52 by arraji            #+#    #+#             */
/*   Updated: 2020/02/18 01:37:54 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

/*
**0->delta
**1->a
**2->b
**3->c
*/

int		cone_inter(t_obj *o, t_camera camera, double *t)
{
	double		vars[4];
	double		new_t[2];
	t_cord		cam_ori;

	cam_ori = vector_sub(camera.pos, o->pos);
	vars[1] = dot_pr(camera.v_ray, camera.v_ray) - ((1 + (o->diam * o->diam))
	* (dot_pr(camera.v_ray, o->orient) * dot_pr(camera.v_ray, o->orient)));
	vars[2] = 2 * (dot_pr(camera.v_ray, cam_ori) - ((1 + (o->diam * o->diam))
	* (dot_pr(camera.v_ray, o->orient) * dot_pr(o->orient, cam_ori))));
	vars[3] = dot_pr(cam_ori, cam_ori) - ((1 + (o->diam * o->diam)) *
	(dot_pr(cam_ori, o->orient) * dot_pr(cam_ori, o->orient)));
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

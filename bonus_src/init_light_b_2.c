/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_b_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 01:10:45 by arraji            #+#    #+#             */
/*   Updated: 2020/02/24 17:37:18 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void	init_cone(t_all all, t_obj *obj, double t)
{
	int		side;
	double	m;

	m = (dot_pr(vector_mltp(all.a_camera->v_ray, t), obj->orient) +
	dot_pr(vector_sub(all.a_camera->pos, obj->pos), obj->orient));
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = all.a_light->type == 0 ?
	vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter)) : vector_mltp(all.a_light->pos, -1);
	obj->norm = vector_norm(vector_sub(vector_sub(all.a_camera->p_inter,
	obj->pos), vector_mltp(obj->orient, (1 + (obj->diam * obj->diam)) * m)));
	side = dot_pr(obj->norm, vector_norm(all.a_camera->v_ray)) > 0 ? -1 : 1;
	obj->norm = vector_norm(vector_mltp(obj->norm, side));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

/*
**[0]->phi
**[1]->theta
**[2]->x
**[3]->y
*/

void	init_uv_sp(t_all all, t_obj *obj, double t)
{
	int		side;
	double	vars[4];
	t_cord	p;

	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	p = all.a_camera->p_inter;
	vars[1] = atan2(-(p.z - obj->pos.z), p.x - obj->pos.x);
	vars[0] = acos(-(p.y - obj->pos.y) / obj->diam);
	vars[2] = (vars[1] + M_PI) / (2 * M_PI) - (M_PI / 12);
	vars[3] = vars[0] / M_PI;
	obj->color = get_pixel_at(obj->texture, vars[2], vars[3]);
	obj->norm = vector_norm(vector_sub(all.a_camera->p_inter,
	obj->pos));
	side = dot_pr(obj->norm, vector_norm(all.a_camera->v_ray)) > 0 ? -1 : 1;
	obj->norm = vector_mltp(obj->norm, side);
	if (!all.a_light)
		return ;
	all.a_light->vec = all.a_light->type == 0 ?
	vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter)) : vector_mltp(all.a_light->pos, -1);
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

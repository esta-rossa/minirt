/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_b_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 01:10:45 by arraji            #+#    #+#             */
/*   Updated: 2020/02/18 01:27:09 by arraji           ###   ########.fr       */
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
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_norm(vector_sub(vector_sub(all.a_camera->p_inter,
	obj->pos), vector_mltp(obj->orient, (1 + (obj->diam * obj->diam)) * m)));
	side = dot_pr(obj->norm, vector_norm(all.a_camera->v_ray)) > 0 ? -1 : 1;
	obj->norm = vector_norm(vector_mltp(obj->norm, side));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

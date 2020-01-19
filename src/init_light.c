/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:47:05 by arraji            #+#    #+#             */
/*   Updated: 2020/01/17 02:45:46 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_sp(t_all all, t_obj *obj, double t)
{
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_norm(vector_sub(all.a_camera->p_inter,
	obj->pos));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

void		init_plan(t_all all, t_obj *obj, double t)
{
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	vector_norm(obj->norm)));
}

void		init_cyl(t_all all, t_obj *obj, double t)
{
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_norm(vector_sub(all.a_camera->p_inter
	, obj->pos));
	obj->norm = vector_norm(vector_mltp(obj->norm, obj->out_hit));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

void		init_tr(t_all all, t_obj *obj, double t)
{
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_norm(vector_sub(all.a_camera->p_inter
	, obj->pos));
	obj->norm = vector_norm(cross_prod(obj->vec_2, obj->vec_1));
	obj->norm = vector_norm(vector_mltp(obj->norm, obj->out_hit));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

void		init_phong(t_all all, t_obj *obj, double t)
{
	if (obj->type == SPHERE)
		init_sp(all, obj, t);
	else if (obj->type == PLANE)
		init_plan(all, obj, t);
	else if (obj->type == CYLINDER)
		init_cyl(all, obj, t);
	else if (obj->type == TRIANGLE)
		init_tr(all, obj, t);
}

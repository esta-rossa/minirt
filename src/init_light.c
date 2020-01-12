/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:47:05 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 20:21:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_sp(t_all all, double t)
{
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	all.a_obj->norm = vector_norm(vector_sub(all.a_camera->p_inter,
	all.a_obj->pos));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	all.a_obj->norm));
}

void		init_plan(t_all all, double t)
{
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	vector_norm(all.a_obj->norm)));
}

void		init_cyl(t_all all, double t)
{
	double m;

	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	all.a_obj->norm));
}

void		init_phong(t_all all, double t)
{
	all.phong->ambient = (t_color){0, 0, 0};
	all.phong->speculare = (t_color){0, 0, 0};
	all.phong->diffuse = (t_color){0, 0, 0};
	if (all.a_obj->type == SPHERE)
		init_sp(all, t);
	else if (all.a_obj->type == PLANE)
		init_plan(all, t);
	else if (all.a_obj->type == CYLINDER)
		init_cyl(all, t);
}

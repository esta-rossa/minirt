/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:47:05 by arraji            #+#    #+#             */
/*   Updated: 2020/02/03 20:50:31 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	init_sp(t_all all, t_obj *obj, double t)
{
	int side;

	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_norm(vector_sub(all.a_camera->p_inter,
	obj->pos));
	side = dot_pr(obj->norm, vector_norm(all.a_camera->v_ray)) > 0 ? -1 : 1;
	obj->norm = vector_mltp(obj->norm, side);
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

static	void	init_plan(t_all all, t_obj *obj, double t)
{
	int		side;

	side = dot_pr(obj->norm, vector_norm(all.a_camera->v_ray)) > 0 ? -1 : 1;
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_mltp(obj->norm, side);
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	vector_norm(obj->norm)));
}

static	void	init_cyl(t_all all, t_obj *obj, double t)
{
	int		side;
	double	m;

	m = (dot_pr(all.a_camera->v_ray, obj->orient) * t) +
	dot_pr(vector_sub(all.a_camera->pos, obj->pos), obj->orient);
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_norm(vector_sub(
	all.a_camera->p_inter, vector_add(obj->pos, vector_mltp(obj->orient, m))));
	side = dot_pr(obj->norm, vector_norm(all.a_camera->v_ray)) > 0 ? -1 : 1;
	obj->norm = vector_norm(vector_mltp(obj->norm, side));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

static	void	init_tr(t_all all, t_obj *obj, double t)
{
	int		side;
	t_cord	vec_1;
	t_cord	vec_2;

	vec_1 = vector_sub(obj->vertex_1, obj->vertex_0);
	vec_2 = vector_sub(obj->vertex_2, obj->vertex_0);
	all.a_camera->p_inter = vector_add(
	all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	obj->norm = vector_norm(vector_sub(all.a_camera->p_inter
	, obj->pos));
	obj->norm = vector_norm(cross_prod(vec_2, vec_1));
	side = dot_pr(obj->norm, vector_norm(all.a_camera->v_ray)) > 0 ? -1 : 1;
	obj->norm = vector_norm(vector_mltp(obj->norm, side));
	all.a_light->reflect = vector_norm(
	reflected(vector_mltp(all.a_light->vec, -1),
	obj->norm));
}

void			init_phong(t_all all, t_obj *obj, double t)
{
	if (obj->type == SPHERE)
		init_sp(all, obj, t);
	else if (obj->type == PLANE)
		init_plan(all, obj, t);
	else if (obj->type == CYLINDER)
		init_cyl(all, obj, t);
	else if (obj->type == TRIANGLE)
		init_tr(all, obj, t);
	else if (obj->type == SQUARE)
		init_plan(all, obj, t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:34:57 by arraji            #+#    #+#             */
/*   Updated: 2020/01/14 09:41:29 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		get_ambiant(t_all *all, t_obj *obj)
{
	double cof;

	all->phong->ambient = (t_color){0, 0, 0};
	cof = all->phong->ambient_cof;
	all->phong->ambient.r = cof * (all->phong->ambient_color.r / 255)
	* (obj->color.r / 255);
	all->phong->ambient.g = cof * (all->phong->ambient_color.g / 255)
	* (obj->color.g / 255);
	all->phong->ambient.b = cof * (all->phong->ambient_color.b / 255)
	* (obj->color.b / 255);
}

void		get_diffuse(t_all *all, t_obj *obj)
{
	double	dot;

	all->phong->diffuse = (t_color){0, 0, 0};
	dot = dot_pr(all->a_light->vec, obj->norm);
	dot = dot < 0 ? 0 : dot;
	all->phong->diffuse.r = all->a_light->bright *
	(obj->color.r / 255) * (all->a_light->color.r / 255) * dot;
	all->phong->diffuse.g = all->a_light->bright *
	(obj->color.g / 255) * (all->a_light->color.g / 255) * dot;
	all->phong->diffuse.b = all->a_light->bright *
	(obj->color.b / 255) * (all->a_light->color.b / 255) * dot;
}

void		get_speculare(t_all *all)
{
	double		factor;

	all->phong->speculare = (t_color){0, 0, 0};
	factor = pow(fmax(dot_pr(all->a_light->reflect,
	vector_mltp(all->a_camera->v_ray, -1)),
	0.0), 60);
	all->phong->speculare.r = all->a_light->bright
	* (all->a_light->color.r / 255) * factor;
	all->phong->speculare.g = all->a_light->bright
	* (all->a_light->color.g / 255) * factor;
	all->phong->speculare.b = all->a_light->bright
	* (all->a_light->color.b / 255) * factor;
}

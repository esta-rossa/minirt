/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shitting_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:37:34 by arraji            #+#    #+#             */
/*   Updated: 2020/02/18 19:07:18 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void		get_ambiant(t_obj *obj, t_phong *phong)
{
	double cof;

	phong->ambient = (t_color){0, 0, 0};
	cof = phong->ambient_cof;
	phong->ambient.r = cof * (phong->ambient_color.r / 255)
	* (obj->color.r / 255);
	phong->ambient.g = cof * (phong->ambient_color.g / 255)
	* (obj->color.g / 255);
	phong->ambient.b = cof * (phong->ambient_color.b / 255)
	* (obj->color.b / 255);
}

static	void		get_diffuse(t_all *all, t_obj *obj, t_phong *phong)
{
	double	dot;

	phong->diffuse = (t_color){0, 0, 0};
	dot = dot_pr(all->a_light->vec, obj->norm);
	dot = dot < 0 ? 0 : dot;
	if (all->color == 1)
	{
		phong->diffuse.r = obj->norm.z * dot;
		phong->diffuse.g = obj->norm.y * dot;
		phong->diffuse.b = obj->norm.x * dot;
	}
	else
	{
		phong->diffuse.r = all->a_light->bright *
		(obj->color.r / 255) * (all->a_light->color.r / 255) * dot;
		phong->diffuse.g = all->a_light->bright *
		(obj->color.g / 255) * (all->a_light->color.g / 255) * dot;
		phong->diffuse.b = all->a_light->bright *
		(obj->color.b / 255) * (all->a_light->color.b / 255) * dot;
	}
}

static	void		get_speculare(t_all *all, t_phong *phong)
{
	double		factor;

	phong->speculare = (t_color){0, 0, 0};
	factor = pow(fmax(dot_pr(all->a_light->reflect,
	vector_mltp(all->a_camera->v_ray, -1)),
	0.0), 60);
	phong->speculare.r = all->a_light->bright
	* (all->a_light->color.r / 255) * factor;
	phong->speculare.g = all->a_light->bright
	* (all->a_light->color.g / 255) * factor;
	phong->speculare.b = all->a_light->bright
	* (all->a_light->color.b / 255) * factor;
}

void				ft_phong(t_all all, t_obj obj, t_color *color, double t)
{
	t_phong	phong;
	t_light	light;

	phong = *all.phong;
	get_ambiant(&obj, &phong);
	color->r += phong.ambient.r;
	color->g += phong.ambient.g;
	color->b += phong.ambient.b;
	while (all.a_light && 1)
	{
		light = *all.a_light;
		all.a_light = &light;
		init_phong(all, &obj, t);
		get_diffuse(&all, &obj, &phong);
		get_speculare(&all, &phong);
		if (!shadow(all, &obj))
		{
			color->r += phong.speculare.r + phong.diffuse.r;
			color->g += phong.speculare.g + phong.diffuse.g;
			color->b += phong.speculare.b + phong.diffuse.b;
		}
		all.a_light = all.a_light->next;
	}
}

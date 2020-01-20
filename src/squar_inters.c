/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o->inters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:14:52 by arraji            #+#    #+#             */
/*   Updated: 2020/01/20 05:18:40 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_axis(double origin, double direction, double *tab)
{
	double	tmin;
	double	tmax;

	tmin = -1.0 - origin;
	tmax = 1.0 - origin;
	if (fabs(direction) >= NEAR)
	{
		tab[0] = tmin / direction;
		tab[1] = tmax / direction;
	}
	else
	{
		tab[0] = FAR;
		tab[1] = FAR;
	}
	smallest_double(tab, 2);
}

int		squar_inters(t_obj *o, t_camera camera, double *t)
{
	// t_obj	squar;
	double	new_t;
	t_cord	hit;
	t_cord	up;
	t_cord	right;
	t_cord	vec;
	double	alfa_up;
	double	alfa_right;

	/* squar.pos = (t_cord){10,0,5};
	squar.norm = (t_cord){0,0,1};
	squar.diam = 10;
	squar.color = (t_color){255,0,255}; */
	new_t = *t;
	if (plan_inters(*o, camera, &new_t))
	{
		hit = vector_add(camera.pos, vector_mltp(camera.v_ray, new_t));
		vec = vector_sub(hit, o->pos);
		// o->norm.x += 0.0001;
		right = vector_norm(cross_prod(new_cord(0, 1, 0), o->norm));
		up = vector_norm(cross_prod(o->norm, right));
		if (dot_pr(up, vec) <= 0)
			up = vector_mltp(up, -1);
		if (dot_pr(right, vec) <= 0)
			right = vector_mltp(right, -1);
		right = vector_mltp(right, o->diam / 2);
		up = vector_mltp(up, o->diam / 2);
		alfa_up = acos(dot_pr(up, vec) / (vector_size(up) * vector_size(vec)));
		alfa_right = acos(dot_pr(right, vec) / (vector_size(right) * vector_size(vec)));
		if ((vector_size(vec) * cos(alfa_up) < vector_size(up)) &&
		(vector_size(vec) * cos(alfa_right) < vector_size(right)))
		{
			*t = new_t;
			return (1);
		}
		// dot_pr(right, vec) * vector_size(vec))/ (vector_size(right) * vector_size(vec))
	}
	return (0);
}

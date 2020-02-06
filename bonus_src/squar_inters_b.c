/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squar_inters_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 00:48:33 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 10:01:26 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	fix_dir(t_cord *up, t_cord *right, t_cord vec)
{
	if (dot_pr(*up, vec) <= 0)
		*up = vector_mltp(*up, -1);
	if (dot_pr(*right, vec) <= 0)
		*right = vector_mltp(*right, -1);
}

/*
**alfa[0] = up
**alfa[1] = right
*/

static	void	init_vecs(t_cord *up, t_cord *right, t_obj *o)
{
	*right = vector_norm(cross_prod(new_cord(0, 1, NEAR), o->norm));
	*up = vector_norm(cross_prod(o->norm, *right));
	*right = vector_mltp(*right, o->diam / 2);
	*up = vector_mltp(*up, o->diam / 2);
}

int				squar_inters(t_obj *o, t_camera camera, double *t)
{
	double	new_t;
	t_cord	up;
	t_cord	right;
	t_cord	vec;
	double	alfa[2];

	new_t = *t;
	if (plan_inters(o, camera, &new_t))
	{
		vec = vector_sub(vector_add(camera.pos,
		vector_mltp(camera.v_ray, new_t)), o->pos);
		init_vecs(&up, &right, o);
		fix_dir(&up, &right, vec);
		alfa[0] = acos(dot_pr(up, vec) / (vector_size(up) * vector_size(vec)));
		alfa[1] = acos(dot_pr(right, vec) /
		(vector_size(right) * vector_size(vec)));
		if ((vector_size(vec) * cos(alfa[0]) < vector_size(up)) &&
		(vector_size(vec) * cos(alfa[1]) < vector_size(right)))
		{
			*t = new_t;
			return (1);
		}
	}
	return (0);
}

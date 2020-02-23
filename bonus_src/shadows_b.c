/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:15:51 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 15:16:19 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

int	shadow(t_all all, t_obj *obj)
{
	t_camera	hit;
	double		dist;
	int			inter;

	inter = 0;
	hit = *all.a_camera;
	hit.pos = vector_add(hit.p_inter, vector_mltp(obj->norm, NEAR));
	if (all.a_light->type == 0)
	{
		hit.v_ray = vector_norm(vector_sub(all.a_light->pos, hit.pos));
		dist = points_dist(all.a_light->pos, hit.pos);
	}
	else
	{
		hit.v_ray = vector_mltp(all.a_light->pos, -1);
		dist = FAR;
	}
	if (inters(all.a_obj, hit, &dist) >= 0)
		inter = 1;
	return (inter);
}

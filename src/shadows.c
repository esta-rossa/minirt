/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:15:51 by arraji            #+#    #+#             */
/*   Updated: 2020/01/21 00:58:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shadow(t_all all, t_obj *obj)
{
	t_camera	hit;
	double		dist;
	int			inter;

	inter = 0;
	hit = *all.a_camera;
	hit.pos = vector_add(hit.p_inter, vector_mltp(obj->norm, NEAR));
	hit.v_ray = vector_norm(vector_sub(all.a_light->pos, hit.pos));
	dist = points_dist(all.a_light->pos, hit.pos);
	if (inters(all.a_obj, hit, &dist) >= 0)
		inter = 1;
	return (inter);
}

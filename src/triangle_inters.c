/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_inters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:53:36 by arraji            #+#    #+#             */
/*   Updated: 2020/02/03 19:30:57 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	tr_calc(t_tr_needs *need, t_obj *obj, t_camera camera)
{
	need->vec_1 = vector_sub(obj->vertex_1, obj->vertex_0);
	need->vec_2 = vector_sub(obj->vertex_2, obj->vertex_0);
	need->cros_ray_vec2 = cross_prod(camera.v_ray, need->vec_2);
	need->dot_of_cros = dot_pr(need->vec_1, need->cros_ray_vec2);
}

int				triangle_inters(t_obj *o, t_camera camera, double *t)
{
	t_tr_needs	need;
	double		new_t;

	tr_calc(&need, o, camera);
	if (need.dot_of_cros > -NEAR && need.dot_of_cros < NEAR)
		return (0);
	need.sub_ori_ver1 = vector_sub(camera.pos, o->vertex_0);
	need.check = (1.0 / need.dot_of_cros) *
	dot_pr(need.sub_ori_ver1, need.cros_ray_vec2);
	if (need.check < 0.0 || need.check > 1.0)
		return (0);
	need.cros_vec1_sub = cross_prod(need.sub_ori_ver1, need.vec_1);
	need.check2 = (1.0 / need.dot_of_cros) *
	dot_pr(camera.v_ray, need.cros_vec1_sub);
	if (need.check2 < 0.0 || need.check + need.check2 > 1.0)
		return (0);
	new_t = (1.0 / need.dot_of_cros) * dot_pr(need.cros_vec1_sub, need.vec_2);
	if (new_t > NEAR && new_t < *t)
	{
		*t = new_t;
		return (1);
	}
	return (0);
}

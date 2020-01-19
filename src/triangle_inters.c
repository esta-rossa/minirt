/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_inters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:53:36 by arraji            #+#    #+#             */
/*   Updated: 2020/01/17 15:14:08 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	tr_calc(t_obj *obj)
{
	obj->vec_1 = vector_sub(obj->vertex_1, obj->vertex_0);
	obj->vec_2 = vector_sub(obj->vertex_2, obj->vertex_0);
	obj->out_hit = -1;
}

int		triangle_inters(t_obj *o, t_camera camera, double *t)
{
	double	dot_of_cros;
	t_cord	cros_ray_vec2;
	t_cord	cros_vec1_sub;
	double	check;
	double	check2;
	t_cord	sub_ori_ver1;
	double	new_t;

	tr_calc(o);
	cros_ray_vec2 = cross_prod(camera.v_ray, o->vec_2);
	dot_of_cros = dot_pr(o->vec_1, cros_ray_vec2);
	if (dot_of_cros > -NEAR && dot_of_cros < NEAR)
		return (0);
	if (dot_of_cros < 0)
		o->out_hit = 1;
	sub_ori_ver1 = vector_sub(camera.pos, o->vertex_0);
	check = (1.0 / dot_of_cros) * dot_pr(sub_ori_ver1, cros_ray_vec2);
	if (check < 0.0 || check > 1.0)
		return (0);
	cros_vec1_sub = cross_prod(sub_ori_ver1, o->vec_1);
	check2 = (1.0 / dot_of_cros) * dot_pr(camera.v_ray, cros_vec1_sub);
	if (check2 < 0.0 || check + check2 > 1.0)
		return (0);
	new_t = (1.0 / dot_of_cros) * dot_pr(cros_vec1_sub, o->vec_2);
	// printf("%f\n", new_t);
	if (new_t > NEAR && new_t < *t)
	{
		// printf("%f\n", dot_of_cros);
		*t = new_t;
		return (1);
	}
	return (0);
}

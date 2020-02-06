/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_2_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:25:21 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 04:38:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

t_cord		vector_norm(t_cord vec)
{
	double	len;
	t_cord	v_new;

	len = vector_size(vec);
	v_new = vector_div(vec, len);
	return (v_new);
}

t_cord		cross_prod(t_cord u, t_cord v)
{
	t_cord new;

	new.x = (u.y * v.z) - (u.z * v.y);
	new.y = (u.z * v.x) - (u.x * v.z);
	new.z = (u.x * v.y) - (u.y * v.x);
	return (new);
}

double		points_dist(t_cord a, t_cord b)
{
	double result;

	result = sqrt(((b.x - a.x) * (b.x - a.x))
	+ ((b.y - a.y) * (b.y - a.y))
	+ ((b.z - a.z) * (b.z - a.z)));
	return (result);
}

t_cord		new_cord(double x, double y, double z)
{
	t_cord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_cord		reflected(t_cord vector, t_cord norm)
{
	t_cord	reflect;

	reflect = vector_sub(vector, vector_mltp(norm, 2.0 * dot_pr(vector, norm)));
	return (reflect);
}

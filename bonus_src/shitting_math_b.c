/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shitting_math_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:33:51 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 04:38:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void		set_cord(t_cord *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

double		dot_pr(t_cord u, t_cord v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double		deg_to_rad(double deg)
{
	return ((deg * M_PI) / 180);
}

int			cmp_float(double a, double b)
{
	double result;

	result = (a < b) ? b - a : a - b;
	if (result > 0.0001)
		return (0);
	return (1);
}

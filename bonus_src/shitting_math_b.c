/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shitting_math_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:33:51 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 09:47:00 by arraji           ###   ########.fr       */
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

t_cord		rodrigues_rot(t_cord vec, t_cord rot, double angle)
{
	t_cord	new;
	t_cord	cross;
	double	dot;

	cross = cross_prod(rot, vec);
	dot = dot_pr(vec, rot);
	new.x = (vec.x * cos(angle)) + (cross.x * sin(angle)) +
	(rot.x * dot * (1 - cos(angle)));
	new.y = (vec.y * cos(angle)) + (cross.y * sin(angle)) +
	(rot.y * dot * (1 - cos(angle)));
	new.z = (vec.z * cos(angle)) + (cross.z * sin(angle)) +
	(rot.z * dot * (1 - cos(angle)));
	return (new);
}

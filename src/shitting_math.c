/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shitting_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:33:51 by arraji            #+#    #+#             */
/*   Updated: 2020/01/14 02:33:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

double		ft_atof(char *str)
{
	return (atof(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shitting_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:33:51 by arraji            #+#    #+#             */
/*   Updated: 2019/12/07 02:02:37 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	twod_func(double a, double b, double c)
{
	double delta;
	double x;
	double x2;
	delta = b * b - 4 * a * c;
	if (delta < -1)
		return (0);
	if (delta == 0)
		x = (-b)/(2 * a);
	if (delta > 0)
	{
		x2 = (-b - sqrt(delta)) / (2 * a);
		x = (-b + sqrt(delta)) / (2 * a);
	}
	return (x);
}

double		distance(t_cord a, t_cord b)
{
	return (sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)));
}

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
t_cord		*new_point(double x, double y, double z)
{
	t_cord	*new;

	new = malloc(sizeof(t_cord));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

void		set_vector(t_cord *vector ,t_cord a, t_cord b)
{
	vector->x = b.x - a.x;
	vector->y = b.y - a.y;
	vector->z = b.z - a.z;
}

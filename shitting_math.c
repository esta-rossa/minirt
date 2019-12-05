/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shitting_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:33:51 by arraji            #+#    #+#             */
/*   Updated: 2019/12/05 03:02:23 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	twod_func(double a, double b, double c)
{
	double delta;
	double x;
	double x2;
	delta = pow(b, 2) - 4 * a * c;
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

double		distance(t_point a, t_point b)
{
	return (sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)));
}

void		set_point(t_point *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

t_point		*new_point(double x, double y)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
}

int		closest(double val, double comp1, double comp2)
{
	double arg1;
	double arg2;

	arg1 = (val > comp1) ? val - comp1 : comp1 - val;
	arg2 = (val > comp2) ? val - comp2 : comp2 - val;
	if (arg1 < arg2)
		return (1);
	else
		return (2);
}

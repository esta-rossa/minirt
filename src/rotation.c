/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:46:52 by arraji            #+#    #+#             */
/*   Updated: 2020/02/02 01:29:10 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	rot_x(double rad, t_cord *vec)
{
	t_cord	save;

	save = *vec;
	vec->x = save.x;
	vec->y = save.y * cos(rad) + save.z * (-sin(rad));
	vec->z = save.y * sin(rad) + save.z * cos(rad);
}

static	void	rot_y(double rad, t_cord *vec)
{
	t_cord	save;

	save = *vec;
	vec->x = save.x * cos(rad) + save.z * sin(rad);
	vec->y = save.y;
	vec->z = save.x * (-sin(rad)) + save.z * cos(rad);
}

static	void	rot_z(double rad, t_cord *vec)
{
	t_cord	save;

	save = *vec;
	vec->x = save.x * cos(rad) + save.y * (-sin(rad));
	vec->y = save.x * sin(rad) + save.y * cos(rad);
	vec->z = save.z;
}

void			rot(t_pars pars, t_cord *vec)
{
	rot_x(deg_to_rad(ft_atof(pars.tab[0])), vec);
	rot_y(deg_to_rad(ft_atof(pars.tab[1])), vec);
	rot_z(deg_to_rad(ft_atof(pars.tab[2])), vec);
}

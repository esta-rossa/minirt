/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 07:17:34 by arraji            #+#    #+#             */
/*   Updated: 2020/01/19 05:03:40 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		clamp_color(t_color *col, int min, int max)
{
	col->r = (col->r > max) ? max : col->r;
	col->r = (col->r < min) ? min : col->r;
	col->g = (col->g > max) ? max : col->g;
	col->g = (col->g < min) ? min : col->g;
	col->b = (col->b > max) ? max : col->b;
	col->b = (col->b < min) ? min : col->b;
}

int			get_color(t_color col)
{
	char	color[4];

	clamp_color(&col, 0, 1);
	color[0] = col.b * 255;
	color[1] = col.g * 255;
	color[2] = col.r * 255;
	color[3] = 0;
	return (*(int *)color);
}

t_color		color_mltp(t_color color, double num)
{
	t_color new;

	new.r = color.r * num;
	new.g = color.g * num;
	new.b = color.b * num;
	return (new);
}

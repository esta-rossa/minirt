/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 07:17:34 by arraji            #+#    #+#             */
/*   Updated: 2020/02/22 07:10:12 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void		clamp_color(t_color *col, int min, int max)
{
	col->r = (col->r > max) ? max : col->r;
	col->r = (col->r < min) ? min : col->r;
	col->g = (col->g > max) ? max : col->g;
	col->g = (col->g < min) ? min : col->g;
	col->b = (col->b > max) ? max : col->b;
	col->b = (col->b < min) ? min : col->b;
}

t_color		color_add(t_color color_a, t_color color_b)
{
	t_color	new;

	new.r = color_a.r + color_b.r;
	new.g = color_a.g + color_b.g;
	new.b = color_a.b + color_b.b;
	return (new);
}

int			get_int(t_color *col)
{
	char		color[4];

	clamp_color(col, 0, 1);
	color[0] = col->b * 255;
	color[1] = col->g * 255;
	color[2] = col->r * 255;
	color[3] = 0;
	return (*(int *)color);
}

t_color		get_color(int color)
{
	unsigned	char	*clr;
	t_color				result;

	clr = (unsigned char *)&color;
	result.b = (int)clr[0];
	result.g = (int)clr[1];
	result.r = (int)clr[2];
	return (result);
}

t_color		color_mltp(t_color color, double num)
{
	t_color new;

	new.r = color.r * num;
	new.g = color.g * num;
	new.b = color.b * num;
	return (new);
}

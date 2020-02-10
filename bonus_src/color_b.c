/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 07:17:34 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 17:55:48 by arraji           ###   ########.fr       */
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

t_color		average_color(t_color *color)
{
	t_color		new;

	new.r = (color[0].r + color[1].r + color[2].r + color[3].r) / 4;
	new.g = (color[0].g + color[1].g + color[2].g + color[3].g) / 4;
	new.b = (color[0].b + color[1].b + color[2].b + color[3].b) / 4;
	return (new);
}

int			get_color(t_color *col)
{
	char		color[4];

	clamp_color(col, 0, 1);
	color[0] = col->b * 255;
	color[1] = col->g * 255;
	color[2] = col->r * 255;
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

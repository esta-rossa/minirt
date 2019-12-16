/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 02:17:19 by arraji            #+#    #+#             */
/*   Updated: 2019/12/07 02:02:37 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	circle(t_cord o, double ray, void *init, void *wind)
{
	double a;
	double x;
	double y;

	a = 0;
	while (a <= 360)
	{
		x = o.x + ray * cos(a);
		y = o.y + ray * sin(a);
		mlx_pixel_put(init, wind, x, y, 255);
		a += (2 * M_PI) / (8 * ray);
	}
}

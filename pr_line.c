/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:49:26 by arraji            #+#    #+#             */
/*   Updated: 2019/12/07 02:02:37 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <mlx.h>



static	void	line_case_one(t_cord a, t_cord b, void *init, void* wind)
{
	int x;

	x = a.x;
	while (x <= b.x)
	{
		mlx_pixel_put(init, wind, x, a.y + ((b.y - a.y) * (x - a.x) / (b.x - a.x)),
		1666600);
		x++;
	}
}
static	void	line_case_two(t_cord a, t_cord b, void *init, void* wind)
{
	int y;

	y = a.y;
	while (y <= b.y)
	{
		mlx_pixel_put(init, wind, a.x + ((b.x - a.x) * (y - a.y) / (b.y - a.y)), y,
		1666600);
		y++;
	}

}
void	draw_line(t_cord a, t_cord b, void *init, void* wind)
{
	if (a.x <= b.x && (b.x - a.x) >= fabs(b.y - a.y))
		line_case_one(a, b, init, wind);
	else if (a.x >= b.x && (a.x - b.x) >= fabs(b.y - a.y))
		line_case_one(b, a, init, wind);
	else if (a.y <= b.y && (b.y - a.y) >= fabs(b.x - a.x))
		line_case_two(a, b, init, wind);
	else if (a.y >= b.y && (a.y - b.y) >= fabs(b.x - a.x))
		line_case_two(b, a, init, wind);
}
/* int main()
{
	void *init;
	void *wind;

	init = mlx_init();
	wind = mlx_new_window(init,500,500,"hey");
	t_cord *a;
	t_cord *b;

	a = new_point(0, 0);
	b = new_point(500, 500);
	draw_line(*a, *b, init, wind);
	mlx_loop(init);
	ft_end((void **)a,(void **)b,1);
	return 0;
}
 */

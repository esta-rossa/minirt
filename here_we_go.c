/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:27:22 by arraji            #+#    #+#             */
/*   Updated: 2019/12/15 10:17:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_func(t_wind *wind, int size_x, int size_y)
{
	wind->wind_x = size_x;
	wind->wind_y = size_y;
	wind->init = mlx_init();
	wind->wind_p = mlx_new_window(wind->init, size_x, size_y, "oups");
}

void	pr_sphere(t_obj onj, t_wind wind)
{

}

int		main()
{
	t_wind	*wind;
	t_obj	obj;
	int y;
	int x;
	int distance;
	double delta;
	double a;
	double b;
	double c;
	t_cord camera;
	t_sphere sphere;
	t_cord curr;
	t_cord v_ray;
	distance = 100;
	set_cord(&(obj.camera), 0, 0, 0);
	x = 0;
	init_func(wind, 500, 500);
	set_cord(&(obj.sphere.centre), 160,0,0);
	obj.sphere.ray = 90;

	while (x < wind->wind_x)
	{
		y = 0;
		while (y < wind->wind_y)
		{
			set_cord(&(obj.curr), distance, (wind->wind_x / 2) - x, (wind->wind_y / 2) - y);
			set_cord(&(obj.v_ray), distance, ((wind->wind_x) / 2) - x, ((wind->wind_y) / 2) - y);
			a = dot_pr(obj.v_ray, obj.v_ray);
			b = 2 * (dot_pr(obj.camera, obj.v_ray) - dot_pr(obj.sphere.centre, obj.v_ray));
			c = dot_pr(obj.sphere.centre, obj.sphere.centre) - obj.sphere.ray * obj.sphere.ray;
			delta = b * b - 4 * a * c;
			// printf("a %f b %f c %f delta %f\n", a, b, c, delta);
			if (delta > 0)
			{
				mlx_pixel_put(wind->init, wind->wind_p, x, y, 0xFF0000);
			}
			y++;
		}
		x++;
	}

	mlx_loop(wind->init);
	return (0);
}

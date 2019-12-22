/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:27:22 by arraji            #+#    #+#             */
/*   Updated: 2019/12/20 18:18:07 by arraji           ###   ########.fr       */
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

double	inters( t_obj obj, double *t)
{
	double delta;
	double a;
	double b;
	double c;
	int i;
	a = dot_pr(obj.v_ray, obj.v_ray);
	b = -2 * dot_pr(obj.sphere.centre, obj.v_ray);
	c = dot_pr(obj.sphere.centre, obj.sphere.centre) - (obj.sphere.ray * obj.sphere.ray);
	delta = b * b - 4 * a * c;
	if (delta > 0)
	{

		delta = sqrt(delta);
		*t = (((-b + delta) / (2 * a)) < ((-b - delta) / (2 * a)) ?
		((-b + delta) / (2 * a)) : ((-b - delta) / (2 * a)));
		if (*t > 0)
			return (1);
		return (0);
	}
	return (0);
}

int	get_color(t_cord col)
{
	int clr;

	clr = 0;
	col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
	col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
	col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
	clr += (int)col.x;
	clr = clr<<8;
	clr += (int)col.y;
	clr = clr<<8;
	clr += (int)col.z;
	return (clr);
}
int		main()
{
	t_wind	*wind;
	t_obj	obj;
	double t;
	int y;
	int x;
	int clr;
	t_cord color;
	t_cord p;
	t_cord v_l;
	t_cord N;
	int distance;
	double alfa;
	double dt;
	int i;
	t_cord white;
	t_cord light;
	t_cord camera;
	t_sphere sphere;
	t_cord curr;
	t_cord v_ray;
	distance = 100;
	set_cord(&light,150,0,0);
	set_cord(&(obj.camera), 0, 0, 0);
	x = 0;
	init_func(wind, 500, 500);
	set_cord(&(obj.sphere.centre),120, 0, 0);
	obj.sphere.ray = 100;
	set_cord(&white, 255,255,255);
	i = 0;
	while (x < wind->wind_x)
	{
		y = 0;
		while (y < wind->wind_y)
		{
			set_cord(&(obj.v_ray), distance, ((wind->wind_x) / 2) - x, ((wind->wind_y) / 2) - y);
			if (inters(obj, &t))
			{
				i++;
				p = vector_mltp(obj.v_ray, t);
				v_l = vector_norm(vector_sub(light, p));
				N = vector_norm(vector_sub(p, obj.sphere.centre));
				dt = dot_pr(v_l, N);
				alfa = (dt / (vector_size(v_l) * vector_size(N)) > 0) ? dt / (vector_size(v_l) * vector_size(N)) : 0;
				// printf("|%d| %f	%f  %f\n", i, obj.v_ray.y, obj.v_ray.z, t);
				// printf("|%d| %f	%f  %f\n", i, v_l.x, v_l.y, v_l.z);
				set_cord(&color, 199,67,117);
				color = vector_mltp(color, alfa);
				printf("%f		%d\n", dt,   get_color(color));
				mlx_pixel_put(wind->init, wind->wind_p, x, y, get_color(color));
			}
			y++;
		}
		x++;
	}

	mlx_loop(wind->init);
	return (0);
}

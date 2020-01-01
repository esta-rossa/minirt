/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:27:22 by arraji            #+#    #+#             */
/*   Updated: 2019/12/31 03:04:44 by arraji           ###   ########.fr       */
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

double	inters(t_obj obj, t_camera camera, double *t)
{
	double delta;
	double a;
	double b;
	double c;

	a = dot_pr(obj.v_ray, obj.v_ray);
	b = (dot_pr(camera.position, obj.v_ray)
	- dot_pr(obj.sphere.centre, obj.v_ray)) * 2;
	c = dot_pr(obj.sphere.centre, obj.sphere.centre)
	- (obj.sphere.ray * obj.sphere.ray)
	- (2 * dot_pr(obj.sphere.centre, camera.position))
	+ dot_pr(camera.position, camera.position);
	delta = b * b - 4 * a * c;
	if (delta > 0)
	{

		delta = sqrt(delta);
		*t = (((-b + delta) / (2 * a)) < ((-b - delta) / (2 * a)) ?
		((-b + delta) / (2 * a)) : ((-b - delta) / (2 * a)));
		printf("t: %f\n", *t);
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
	col.x = (col.x > 255) ? 255 : col.x;
	col.x = (col.x < 0) ? 0 : col.x;
	col.y = (col.y > 255) ? 255 : col.y;
	col.y = (col.y < 0) ? 0 : col.y;
	col.z = (col.z > 255) ? 255 : col.z;
	col.z = (col.z < 0) ? 0 : col.z;
	clr += (int)col.x;
	clr = clr << 8;
	clr += (int)col.y;
	clr = clr << 8;
	clr += (int)col.z;
	return (clr);
}

t_cord	reflected(t_cord vector, t_cord norm)
{
	t_cord	reflect;

	reflect = vector_sub(vector, vector_mltp(norm, 2 * dot_pr(vector, norm)));
	return (reflect);
}

void	pr_cord(t_cord cord, char *name, char *end)
{
	printf("%s.x: %f %s.y: %f %s.z: %f%s", name, cord.x, name, cord.y, name, cord.z, end);
}

double	get_diffuse()
{

}
int		main()
{
	t_wind	*wind;
	t_obj	obj;
	double t;
	int y;
	int x;
	t_cord color;
	t_cord p;
	t_cord v_l;
	t_cord N;
	double ambiant;
	double diffuse;
	t_cord bot;
	t_cord white;
	t_cord light;
	t_camera camera;
	camera.position = new_cord(0, 0, 0);
	camera.l_at = new_cord(1,0, 0);
	camera.fov = 90;
	camera.x_reso = 500;
	camera.y_reso = 500;
	set_cord(&light,0, 0, 250);
	y = 0;
	init_func(wind, 500, 500);
	set_cord(&(obj.sphere.centre), 120, 0, 0);
	set_cord(&(obj.sphere2.centre), 120, 0, -50);
	obj.sphere.ray = 50;
	obj.sphere2.ray = 50;
	set_cord(&white, 255,255,255);
	bot = init_camera(&camera);
	while (y < camera.y_reso)
	{
		x = 0;
		while (x < camera.x_reso)
		{
			obj.v_ray = get_ray(camera, bot, x, y);
			// set_cord(&(obj.v_ray), distance, ((wind->wind_x) / 2) - x, ((wind->wind_y) / 2) - y);
			if (inters(obj, camera, &t))
			{
			// pr_cord(obj.v_ray, "ray", "\n");
				// pr_cord(bot, "bot", "\n");
				p = vector_mltp(obj.v_ray, t);
				v_l = vector_norm(vector_sub(light, p));
				N = vector_norm(vector_sub(p, obj.sphere.centre));
				diffuse = dot_pr(v_l, N) > 0 ? dot_pr(v_l, N) : 0;
				ambiant = 0.5;
				// printf("|%d| %f	%f  %f\n", i, obj.v_ray.y, obj.v_ray.z, t);
				// printf("|%d| %f	%f  %f\n", i, v_l.x, v_l.y, v_l.z);
				set_cord(&color, 255, 0, 0);
				color = vector_mltp(color, (diffuse ));
				// printf("diffuse :%f	specular :%f ambiant :%f t :%f \npx: %f py: %f pz:%f %d\n", diffuse, specular, ambiant, t, p.x, p.y, p.z, get_color(color));
				// printf("lx: %f ly: %f ly: %f  nx: %f nx: %f nx: %f \n\n",v_l.x, v_l.y, v_l.z, N.x, N.y, N.z);
				mlx_pixel_put(wind->init, wind->wind_p, x, y, get_color(color));
			}
			x++;
		}
		y++;
	}
	mlx_loop(wind->init);
	return (0);
}

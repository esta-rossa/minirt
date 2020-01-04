/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:27:22 by arraji            #+#    #+#             */
/*   Updated: 2020/01/04 09:54:55 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_func(t_wind *wind, int size_x, int size_y)
{
	int		bpp;
	int		size_line;
	int		endian;

	wind->wind_x = size_x;
	wind->wind_y = size_y;
	wind->init = mlx_init();
	wind->wind_p = mlx_new_window(wind->init, size_x, size_y, "oups");
	wind->img_p = mlx_new_image(wind->init, 500, 500);
	wind->img_data = (int *)mlx_get_data_addr(wind->img_p, &bpp, &size_line, &endian);
}

int	sp_inters(t_obj obj, t_camera camera, double *t)
{
	double delta;
	double a;
	double b;
	double c;

	a = dot_pr(camera.v_ray, camera.v_ray);
	b = (dot_pr(camera.pos, camera.v_ray)
	- dot_pr(obj.pos, camera.v_ray)) * 2;
	c = dot_pr(obj.pos, obj.pos)
	- (obj.ray * obj.ray)
	- (2 * dot_pr(obj.pos, camera.pos))
	+ dot_pr(camera.pos, camera.pos);
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

int	inters(t_obj *obj, t_camera camera, double *t)
{
	double t_tmp;
	int inter;
	int index;
	int pos;

	pos = 0;
	index = 0;
	inter = 0;
	t_tmp = 1e30;
	while (obj)
	{
		if (sp_inters(*obj, camera, t))
		{
			inter = 1;
			if (*t < t_tmp)
			{
				pos = index;
				t_tmp = *t;
			}
		}
		index++;
		obj = obj->next;
	}
	*t = t_tmp;
	return (inter == 1 ? pos : -1);
}

int	get_color(t_color col)
{
	int clr;

	clr = 0;
	col.r = (col.r > 255) ? 255 : col.r;
	col.r = (col.r < 0) ? 0 : col.r;
	col.g = (col.g > 255) ? 255 : col.g;
	col.g = (col.g < 0) ? 0 : col.g;
	col.b = (col.b > 255) ? 255 : col.b;
	col.b = (col.b < 0) ? 0 : col.b;
	return ((col.r << 16) + (col.g << 8) + (col.b));
}

t_cord	reflected(t_cord vector, t_cord norm)
{
	t_cord	reflect;

	reflect = vector_sub(vector, vector_mltp(norm, 2 * dot_pr(vector, norm)));
	return (reflect);
}

void		pr_cord(t_cord cord, char *name, char *end)
{
	printf("%s.x: %f %s.y: %f %s.z: %f%s", name, cord.x, name, cord.y, name, cord.z, end);
}
t_color		color_mltp(t_color color, double num)
{
	t_color new;

	new.r = color.r * num;
	new.g = color.g * num;
	new.b = color.b * num;
	return (new);
}

void		set_color(t_color *color, double r, double g, double b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

t_color		new_color(double r, double g, double b)
{
	t_color new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

double		get_diffuse(t_camera camera, t_obj obj, t_cord light, double t)
{
	t_cord p;
	t_cord v_l;
	t_cord N;

	double diffuse;
	p = vector_mltp(camera.v_ray, t);
	v_l = vector_norm(vector_sub(light, p));
	N = vector_norm(vector_sub(p, obj.pos));
	diffuse = dot_pr(v_l, N);
	return (diffuse);
}

void	fill_img(char *image, t_color color, int index)
{
	image[index++] = color.r;
	image[index++] = color.g;
	image[index] = color.b;
}

void		render(t_all all, t_camera camera, t_cord light, t_color *color)
{
	double ambiant;
	double diffuse;
	int pos;
	double t;

	*color = new_color(0,0,0);
	if ((pos = inters(all.a_obj, camera, &t)) >= 0)
	{
		while (pos--)
			all.a_obj = all.a_obj->next;
		diffuse = get_diffuse(camera, *(all).a_obj, light, t);
		ambiant = 0.5;
		*color = all.a_obj->color;
		*color = color_mltp(*color, (diffuse));
	}
}

void		here_we_go(t_all *all)
{
	int y;
	int x;
	int	*img_save;
	t_color color;
	t_cord white;
	t_cord light;
	all->a_camera->x_reso = 500;
	all->a_camera->y_reso = 500;
	set_cord(&light, 0, 0, 0);
	y = 0;
	init_func(&(all)->wind, 500, 500);
	set_cord(&white, 255,255,255);
	init_camera(all->a_camera);
	img_save = all->wind.img_data;
	while (y < all->a_camera->y_reso)
	{
		x = 0;
		while (x < all->a_camera->x_reso)
		{
			all->a_camera->v_ray = get_ray(*(all)->a_camera,
			all->a_camera->bot, x, y);
			render(*all, *(all)->a_camera, light, &color);
			*img_save = get_color(color);
			img_save++;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->wind.init, all->wind.wind_p,
	all->wind.img_p, 0, 0);
}

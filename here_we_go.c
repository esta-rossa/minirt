/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:27:22 by arraji            #+#    #+#             */
/*   Updated: 2020/01/06 22:13:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_func(t_all all)
{
	int		bpp;
	int		size_line;
	int		endian;

	all.wind->init = mlx_init();
	all.wind->wind_p = mlx_new_window(all.wind->init, all.wind->wind_x,
	all.wind->wind_y, "oups");
	all.wind->img_p = mlx_new_image(all.wind->init, all.wind->wind_x,
	all.wind->wind_y);
	all.wind->img_data = (int *)mlx_get_data_addr(all.wind->img_p, &bpp,
	&size_line, &endian);
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
	double	t_tmp;
	int		inter;
	int		index;
	int		pos;

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

void		clamp_color(t_color *col, int min, int max)
{
	col->r = (col->r > max) ? max : col->r;
	col->r = (col->r < min) ? min : col->r;
	col->g = (col->g > max) ? max : col->g;
	col->g = (col->g < min) ? min : col->g;
	col->b = (col->b > max) ? max : col->b;
	col->b = (col->b < min) ? min : col->b;
}

int	get_color(t_color col)
{
	char	color[4];

	clamp_color(&col, 0, 1);
	color[0] = col.b * 255;
	color[1] = col.g * 255;
	color[2] = col.r * 255;
	color[3] = 0;
	return (*(int *)color);
}

t_cord	reflected(t_cord vector, t_cord norm)
{
	t_cord	reflect;

	reflect = vector_sub(vector, vector_mltp(norm, 2.0 * dot_pr(vector, norm)));
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

void	get_diffuse(t_all *all, double t)
{
	double	dot;

	dot = dot_pr(all->a_light->vec, all->a_obj->norm);
	dot = dot < 0 ? 0 : dot;
	all->phong->diffuse.r = 0.7 * all->a_light->bright *
	(all->a_obj->color.r / 255) * (all->a_light->color.r / 255) * dot;
	all->phong->diffuse.g = 0.7 * all->a_light->bright *
	(all->a_obj->color.g / 255) * (all->a_light->color.g / 255) * dot;
	all->phong->diffuse.b = 0.7 * all->a_light->bright *
	(all->a_obj->color.b / 255) * (all->a_light->color.b / 255) * dot;
}

void		get_speculare(t_all *all, double t)
{
	double		factor;

	factor = pow(fmax(dot_pr(all->a_light->reflect,
	vector_mltp(all->a_camera->v_ray, -1)),
	0.0), 60);
	all->phong->speculare.r = 0.5 * all->a_light->bright
	* (all->a_light->color.r / 255) * factor;
	all->phong->speculare.g = 0.5 * all->a_light->bright
	* (all->a_light->color.g / 255) * factor;
	all->phong->speculare.b = 0.5 * all->a_light->bright
	* (all->a_light->color.b / 255) * factor;
}

void		get_ambiant(t_all *all, double t)
{
	double cof;

	cof = all->phong->ambient_cof;
	all->phong->ambient.r = cof * (all->phong->ambient_color.r / 255)
	* (all->a_obj->color.r / 255);
	all->phong->ambient.g = cof * (all->phong->ambient_color.g / 255)
	* (all->a_obj->color.g / 255);
	all->phong->ambient.b = cof * (all->phong->ambient_color.b / 255)
	* (all->a_obj->color.b / 255);
}

void		init_phong(t_all all, double t)
{
	all.phong->ambient = (t_color){0, 0, 0};
	all.phong->speculare = (t_color){0, 0, 0};
	all.phong->diffuse = (t_color){0, 0, 0};
	all.a_camera->p_inter = vector_add(all.a_camera->pos, vector_mltp(all.a_camera->v_ray, t));
	all.a_light->vec = vector_norm(vector_sub(all.a_light->pos,
	all.a_camera->p_inter));
	all.a_obj->norm = vector_norm(vector_sub(all.a_camera->p_inter,
	all.a_obj->pos));
	all.a_light->reflect = vector_norm(reflected(vector_mltp(all.a_light->vec, -1),
	all.a_obj->norm));
}

void		ft_phong(t_all all, t_color *color, double t)
{
	t_light	*list;

	init_phong(all, t);
	list = all.a_light;
	get_diffuse(&all, t);
	get_speculare(&all, t);
	get_ambiant(&all, t);
	color->r = all.phong->ambient.r + all.phong->speculare.r
	+ all.phong->diffuse.r;
	color->g = all.phong->ambient.g + all.phong->speculare.g
	+ all.phong->diffuse.g;
	color->b = all.phong->ambient.b + all.phong->speculare.b
	+ all.phong->diffuse.b;
}

void		render(t_all all, t_camera camera, t_light light, t_color *color)
{
	int pos;
	double t;

	*color = (t_color){ 0, 0, 0};
	if ((pos = inters(all.a_obj, camera, &t)) >= 0)
	{
		while (pos--)
			all.a_obj = all.a_obj->next;
		ft_phong(all, color, t);
		// *color = all.a_obj->color;
	}
}

void		here_we_go(t_all *all)
{
	int			y;
	int			x;
	t_color		color;

	y = -1;
	init_func(*all);
	init_camera(all->a_camera, *all);
	while (++y < all->wind->wind_y)
	{
		x = -1;
		while (++x < all->wind->wind_x)
		{
			all->a_camera->v_ray = get_ray(*(all)->a_camera,
			all->a_camera->bot, x, y);
			render(*all, *(all)->a_camera, *(all)->a_light, &color);
			*(all->wind)->img_data = get_color(color);
			(all->wind)->img_data++;
		}
	}
	mlx_put_image_to_window(all->wind->init, all->wind->wind_p,
	all->wind->img_p, 0, 0);
}

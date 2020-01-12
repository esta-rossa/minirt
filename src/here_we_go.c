/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:50:24 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 20:21:13 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_func(t_all all)
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

void		render(t_all all, t_camera camera, t_light light, t_color *color)
{
	int			pos;
	double		t;

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
			all->a_camera->v_ray = vector_norm(get_ray(*(all)->a_camera,
			all->a_camera->bot, x, y));
			render(*all, *(all)->a_camera, *(all)->a_light, &color);
			*(all->wind)->img_data = get_color(color);
			(all->wind)->img_data++;
		}
	}
	mlx_put_image_to_window(all->wind->init, all->wind->wind_p,
	all->wind->img_p, 0, 0);
}

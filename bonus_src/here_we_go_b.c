/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:50:24 by arraji            #+#    #+#             */
/*   Updated: 2020/02/24 18:00:52 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void		init_wind(t_all all)
{
	if (!(all.wind->init = mlx_init()))
		ft_exit(E_STD);
	if (all.save == 0)
		if (!(all.wind->wind_p = mlx_new_window(all.wind->init,
		all.wind->wind_x, all.wind->wind_y, "minirt")))
			ft_exit(E_STD);
}

void		init_image(t_all all)
{
	int		bpp;
	int		size_line;
	int		endian;

	if (!(all.wind->img_p = mlx_new_image(all.wind->init, all.wind->wind_x,
	all.wind->wind_y)))
		ft_exit(E_STD);
	all.wind->img_data = (int *)mlx_get_data_addr(all.wind->img_p, &bpp,
	&size_line, &endian);
}

void		render(t_all all, t_camera camera, t_color *color, t_cord v_ray)
{
	int			pos;
	double		t;
	t_obj		*obj;

	*color = (t_color){ 0, 0, 0};
	t = FAR;
	camera.v_ray = v_ray;
	all.a_camera = &camera;
	if ((pos = inters(all.a_obj, camera, &t)) >= 0)
	{
		obj = all.a_obj;
		while (pos--)
			obj = obj->next;
		ft_phong(all, *obj, color, t);
	}
}

void		put_image(t_all *all)
{
	all->save == 0 ? mlx_put_image_to_window(all->wind->init, all->wind->wind_p,
	all->wind->img_p, 0, 0) : save_bitmap(*all->wind, all->wind->img_data);
}

void		here_we_go(t_all *all)
{
	g_all = all;
	init_image(*all);
	init_camera(all->a_camera, *all);
	if (all->str != 0)
		stereoscopy_render(all);
	else
	{
		threads_parent();
		all->filter == 1 ? filter(all->wind->img_data) : 1;
	}
}

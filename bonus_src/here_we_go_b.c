/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:50:24 by arraji            #+#    #+#             */
/*   Updated: 2020/02/07 03:42:21 by arraji           ###   ########.fr       */
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

void		render(t_all all, t_camera camera, t_color *color)
{
	int			pos;
	double		t;
	t_obj		*obj;

	*color = (t_color){ 0, 0, 0};
	t = FAR;
	if ((pos = inters(all.a_obj, camera, &t)) >= 0)
	{
		obj = all.a_obj;
		while (pos--)
			obj = obj->next;
		ft_phong(all, obj, color, t);
	}
}

void		*threads_child(void *param)
{
	t_color	color;
	int		*img;

	img = (int *)param;
	render(*all_save, *all_save->a_camera, &color);
	*img = get_color(color);
	return (NULL);
}

void		hold_threads(pthread_t *threads, int size)
{
	int		index;

	index = 0;
	while (index < size)
	{
		pthread_join(threads[index], NULL);
		index++;
	}
}

void		thread_parent(pthread_t *threads, int index, int *img)
{
	pthread_join(threads[index], NULL);
	pthread_create(&threads[index], NULL, threads_child, img);
}

void		here_we_go(t_all *all)
{
	int			y;
	int			x;
	pthread_t	thread[1];
	int			index;

	index = 0;
	y = all->wind->wind_y + 1;
	init_image(*all);
	init_camera(all->a_camera, *all);
	all_save = all;
	while (--y > 0)
	{
		x = -1;
		while (++x < all->wind->wind_x)
		{
			index = index >= 1 ? 0 : index;
			all->a_camera->v_ray = get_ray(*(all)->a_camera,
			all->a_camera->bot, x, y);
			thread_parent(thread, index, all->wind->img_data);
			(all->wind)->img_data++;
			index++;
		}
	}
	hold_threads(thread, 1);
	all->save == 0 ? mlx_put_image_to_window(all->wind->init, all->wind->wind_p,
	all->wind->img_p, 0, 0) : save_bitmap(*all->wind, all->wind->img_data);
}

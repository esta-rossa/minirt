/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:37:05 by arraji            #+#    #+#             */
/*   Updated: 2020/02/08 11:06:58 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

/*
**indexs[0]->y
**indexs[1]->x
**indexs[2]-> stop
*/

void		get_all_rays(t_cord *v_rays, double x, double y)
{
	v_rays[0] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x + 0.5 , y + 0.5);
	v_rays[1] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x + 0.5, y - 0.5);
	v_rays[2] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x - 0.5, y + 0.5);
	v_rays[3] = get_ray(*(all_save)->a_camera,
	all_save->a_camera->bot, x - 0.5, y - 0.5);
}

void		render_all_ray(t_color *colors, t_cord *v_rays)
{
	render(*all_save, *all_save->a_camera, &colors[0], v_rays[0]);
	render(*all_save, *all_save->a_camera, &colors[1], v_rays[1]);
	render(*all_save, *all_save->a_camera, &colors[2], v_rays[2]);
	render(*all_save, *all_save->a_camera, &colors[3], v_rays[3]);
}

void		*thread_child(void *param)
{
	int		indexs[3];
	t_cord	v_rays[4];
	t_color colors[4];
	int		*img;
	long	step;

	step = (int)param;
	indexs[0] = (((all_save->wind->wind_y) / 4) * step) + 1;
	img = all_save->wind->img_data;
	indexs[2] = indexs[0] - ((all_save->wind->wind_y) / 4) - 1;
	img += (all_save->wind->wind_y - indexs[0] - 1) * all_save->wind->wind_x;
	while (--indexs[0] > indexs[2])
	{
		indexs[1] = -1;
		while (++indexs[1] < all_save->wind->wind_x)
		{
			get_all_rays((t_cord *)&v_rays, indexs[1], indexs[0]);
			render_all_ray((t_color *)&colors, (t_cord *)&v_rays);
			// v_rays = get_ray(*(all_save)->a_camera,
			// all_save->a_camera->bot, indexs[1], indexs[0]);
			// render(*all_save, *all_save->a_camera, &colors, v_rays);
			*img = get_color(colors[0]);
			img++;
		}
	}
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

void		threads_parent(void)
{
	pthread_t	threads[4];
	long		part;

	part = 1;
	while (part < 5)
	{
		if (pthread_create(&threads[part - 1],
		NULL, thread_child, (void*)part) != 0)
			ft_exit(E_STD);
		part++;
	}
	hold_threads(threads, 4);
}

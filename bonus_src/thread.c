/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:37:05 by arraji            #+#    #+#             */
/*   Updated: 2020/02/09 02:24:52 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

/*
**indexs[0]->y
**indexs[1]->x
**indexs[2]-> stop
*/

void		*thread_child(void *param)
{
	int		indexs[3];
	t_cord	v_rays[4];
	t_color colors[4];
	int		*img;
	long	step;

	step = (int)param;
	indexs[0] = (((all_save->wind->wind_y) / 4) * step);
	img = all_save->wind->img_data;
	indexs[2] = indexs[0] - ((all_save->wind->wind_y) / 4);
	img += (all_save->wind->wind_y - indexs[0]) * all_save->wind->wind_x;
	while (--indexs[0] > indexs[2])
	{
		indexs[1] = -1;
		while (++indexs[1] < all_save->wind->wind_x)
		{
			get_all_rays(v_rays, indexs[1], indexs[0]);
			render_all_ray(colors, v_rays);
			*img = get_color(colors);
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
		if (pthread_join(threads[index], NULL) != 0)
			ft_exit(E_STD);
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

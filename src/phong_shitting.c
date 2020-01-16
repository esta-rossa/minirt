/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:37:34 by arraji            #+#    #+#             */
/*   Updated: 2020/01/15 21:50:27 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_phong(t_all all, t_obj *obj, t_color *color, double t)
{

	get_ambiant(&all, obj);
	color->r += all.phong->ambient.r;
	color->g += all.phong->ambient.g;
	color->b += all.phong->ambient.b;
	while (all.a_light && 1)
	{
		init_phong(all, obj, t);
		get_diffuse(&all, obj);
		get_speculare(&all);
		if (!shadow(all, obj))
		{
			color->r += all.phong->speculare.r + all.phong->diffuse.r;
			color->g += all.phong->speculare.g + all.phong->diffuse.g;
			color->b += all.phong->speculare.b + all.phong->diffuse.b;
		}
		/* color->r += all.phong->speculare.r + all.phong->diffuse.r;
		color->g += all.phong->speculare.g + all.phong->diffuse.g;
		color->b += all.phong->speculare.b + all.phong->diffuse.b; */
		all.a_light = all.a_light->next;
	}
	// printf("c %f %f %f", color->r, color->g, color->b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:37:34 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 21:12:29 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	// printf("c %f %f %f", color->r, color->g, color->b);
}

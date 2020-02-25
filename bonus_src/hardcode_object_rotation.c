/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_object_rotation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:49:28 by arraji            #+#    #+#             */
/*   Updated: 2020/02/25 00:53:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	cylinder_rot(t_obj *obj, t_cord vec)
{
	obj->orient = rodrigues_rot(obj->orient, vec, M_PI / 8);
	if (obj->cap == 1)
	{
		obj->next->pos = vector_add(obj->pos,
		vector_mltp(obj->orient, obj->height / 2));
		obj->next->norm = rodrigues_rot(obj->next->norm, vec, M_PI / 8);
		obj->next->next->pos = vector_add(obj->pos,
		vector_mltp(obj->orient, (-obj->height) / 2));
		obj->next->next->norm =
		rodrigues_rot(obj->next->next->norm, vec, M_PI / 8);
	}
}

void			object_rot(t_obj *obj, t_cord vec)
{
	if (obj->type == TRIANGLE || obj->type == SPHERE || obj->type == UV_SPHERE)
		return ;
	else if ((obj->type == SQUARE || (obj->type == TRIANGLE))
	&& (obj->sp_type == PYRAMID))
		return ;
	else if (obj->type == SQUARE && obj->sp_type == CUBE)
		return ;
	else if (obj->type == CYLINDER ||
	(obj->type == DISK && obj->sp_type == CAP))
		cylinder_rot(obj->head, vec);
	else if (obj->type == CONE)
		obj->orient = rodrigues_rot(obj->orient, vec, M_PI / 8);
	else
		obj->norm = rodrigues_rot(obj->norm, vec, M_PI / 8);
}

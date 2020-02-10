/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_object_translation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:35:08 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 17:56:01 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	triangle_trans(t_obj *obj, t_cord vec)
{
	obj->vertex_0 = vector_add(obj->vertex_0, vector_mltp(vec, 5));
	obj->vertex_1 = vector_add(obj->vertex_1, vector_mltp(vec, 5));
	obj->vertex_2 = vector_add(obj->vertex_2, vector_mltp(vec, 5));
}

static	void	cylinder_trans(t_obj *obj, t_cord vec)
{
	obj->pos = vector_add(obj->pos, vector_mltp(vec, 5));
	if (obj->cap)
	{
		obj->next->pos = vector_add(obj->next->pos, vector_mltp(vec, 5));
		obj->next->next->pos = vector_add(
		obj->next->next->pos, vector_mltp(vec, 5));
	}
}

static	void	pyramid_trans(t_obj *obj, t_cord vec)
{
	obj->pos = vector_add(obj->pos, vector_mltp(vec, 5));
	triangle_trans(obj->next, vec);
	triangle_trans(obj->next->next, vec);
	triangle_trans(obj->next->next->next, vec);
	triangle_trans(obj->next->next->next->next, vec);
}

static	void	cube_trans(t_obj *obj, t_cord vec)
{
	int		index;

	index = 0;
	while (index < 6)
	{
		obj->pos = vector_add(obj->pos, vector_mltp(vec, 5));
		obj = obj->next;
		index++;
	}
}

void			object_trans(t_obj *obj, t_cord vec)
{
	if (obj->type == TRIANGLE && obj->sp_type == 0)
		triangle_trans(obj, vec);
	else if (obj->type == TRIANGLE && obj->sp_type == PYRAMID)
		pyramid_trans(obj->head, vec);
	else if (obj->type == CYLINDER)
		cylinder_trans(obj, vec);
	else if (obj->type == DISK && obj->sp_type == CAP)
		cylinder_trans(obj->head, vec);
	else if (obj->type == SQUARE && obj->sp_type == PYRAMID)
		pyramid_trans(obj->head, vec);
	else if (obj->type == SQUARE && obj->sp_type == CUBE)
		cube_trans(obj->head, vec);
	else
		obj->pos = vector_add(obj->pos, vector_mltp(vec, 5));
}

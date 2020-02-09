/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 04:11:53 by arraji            #+#    #+#             */
/*   Updated: 2020/02/08 22:01:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

int		disk_inters(t_obj *o, t_camera camera, double *t)
{
	double	save;
	t_cord	p;
	t_cord	vec;
	double	dis;

	save = *t;
	if (plan_inters(o, camera, &save))
	{
		p = vector_add(camera.pos, vector_mltp(camera.v_ray, save));
		vec = vector_sub(p, o->pos);
		dis = sqrt(dot_pr(vec, vec));
		if (dis <= o->diam / 2)
		{
			*t = save;
			return (1);
		}
	}
	return (0);
}

void	put_cap(t_pars *pars, t_all *list)
{
	t_obj	*obj;
	t_obj	new;

	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	if (obj->cap != 1 && obj->cap != 0)
		ft_pars_exit(*pars, E_PARS);
	if (obj->cap == 0)
		return ;
	obj->orient = vector_norm(obj->orient);
	add_obj(&(list)->a_obj, new_obj());
	new = *obj;
	obj = obj->next;
	obj->type = DISK;
	obj->pos = vector_add(new.pos, vector_mltp(new.orient, new.height / 2));
	obj->color = new.color;
	obj->norm = new.orient;
	obj->diam = new.diam;
	add_obj(&(list)->a_obj, new_obj());
	*obj->next = *obj;
	obj = obj->next;
	obj->next = NULL;
	obj->pos = vector_add(new.pos, vector_mltp(new.orient, (-new.height) / 2));
}

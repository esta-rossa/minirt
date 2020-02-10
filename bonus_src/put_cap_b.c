/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 04:11:53 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 17:59:24 by arraji           ###   ########.fr       */
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

void	put_cap(t_pars *pars, t_obj *obj)
{
	t_obj	new;

	obj->orient = vector_norm(obj->orient);
	obj->head = obj;
	if (obj->cap != 1 && obj->cap != 0)
		ft_pars_exit(*pars, E_PARS);
	if (obj->cap == 0)
		return ;
	add_obj(&obj, new_obj());
	new = *obj;
	obj->next->head = obj;
	obj = obj->next;
	obj->sp_type = CAP;
	obj->type = DISK;
	obj->pos = vector_add(new.pos, vector_mltp(new.orient, new.height / 2));
	obj->color = new.color;
	obj->norm = new.orient;
	obj->diam = new.diam;
	add_obj(&obj, new_obj());
	*obj->next = *obj;
	obj = obj->next;
	obj->next = NULL;
	obj->pos = vector_add(new.pos, vector_mltp(new.orient, (-new.height) / 2));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_pars_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 01:26:01 by arraji            #+#    #+#             */
/*   Updated: 2020/02/09 03:42:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	rot_obj(t_pars pars, t_obj *obj)
{
	int	type;

	type = obj->type;
	if (type == SPHERE || type == TRIANGLE)
		ft_pars_exit(pars, E_PARS);
	else if (type == CYLINDER)
	{
		rot(pars, &obj->orient);
		if (obj->cap == 1)
		{
			obj->next->pos = vector_add(obj->pos,
			vector_mltp(obj->orient, obj->height / 2));
			rot(pars, &obj->next->norm);
			obj->next->next->pos = vector_add(obj->pos,
			vector_mltp(obj->orient, (-obj->height) / 2));
			rot(pars, &obj->next->next->norm);
		}
	}
	else
		rot(pars, &obj->norm);
}

void			rot_pars(t_pars *pars, t_all *list, char **args)
{
	int type;

	type = list->last->type;
	if (ft_tablen(args) != 2)
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 1);
	pars->tab = ft_split(args[1], ',');
	if (type == AMB || type == LIGHT || type == 0 ||
	type == CUBE || type == PYRAMID)
		ft_pars_exit(*pars, E_PARS);
	else if (type == CAM)
		rot(*pars, &list->a_camera->l_at);
	else if (type == OBJ)
		rot_obj(*pars, list->last->save);
	free_tab(pars->tab, 3);
}

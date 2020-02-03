/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 00:30:52 by arraji            #+#    #+#             */
/*   Updated: 2020/02/02 06:23:16 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	translation(t_pars pars, t_cord *pos)
{
	t_cord	vec;

	vec.x = ft_atof(pars.tab[0]);
	vec.y = ft_atof(pars.tab[1]);
	vec.z = ft_atof(pars.tab[2]);
	*pos = vector_add(*pos, vec);
}

static	void	translation_obj(t_pars pars, t_obj *obj)
{
	while (obj->next)
		obj = obj->next;
	if (obj->type == TRIANGLE)
	{
		translation(pars, &obj->vertex_0);
		translation(pars, &obj->vertex_1);
		translation(pars, &obj->vertex_2);
	}
	else
		translation(pars, &obj->pos);
}

void			tran_pars(t_pars *pars, t_all *list, char **args)
{
	int			type;
	t_light		*save;

	type = list->last->type;
	if (ft_tablen(args) != 2)
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	pars->tab = ft_split(args[1], ',');
	if (type == AMB || type == 0)
		ft_pars_exit(*pars, E_PARS);
	else if (type == CAM)
		translation(*pars, &list->a_camera->pos);
	else if (type == OBJ)
		translation_obj(*pars, list->a_obj);
	else if (type == LIGHT)
	{
		save = list->a_light;
		while (save->next)
			save = save->next;
		translation(*pars, &save->pos);
	}
}

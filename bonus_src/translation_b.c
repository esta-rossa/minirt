/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 00:30:52 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 15:01:43 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

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
	if (obj->type == TRIANGLE)
	{
		translation(pars, &obj->vertex_0);
		translation(pars, &obj->vertex_1);
		translation(pars, &obj->vertex_2);
	}
	else
		translation(pars, &obj->pos);
}

void			translate_compound(t_obj *cube, t_pars pars, int type)
{
	int	index;

	index = 6;
	if (type == PYRAMID)
		index--;
	while (index--)
	{
		translation_obj(pars, cube);
		cube = cube->next;
	}
}

void			tran_pars(t_pars *pars, t_all *list, char **args)
{
	t_light		*save;

	if (ft_tablen(args) != 2)
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	pars->tab = ft_split(args[1], ',');
	if (list->last->type == AMB || list->last->type == 0)
		ft_pars_exit(*pars, E_PARS);
	else if (list->last->type == CAM)
		translation(*pars, &list->a_camera->pos);
	else if (list->last->type == OBJ)
		translation_obj(*pars, list->last->save);
	else if (list->last->type == CUBE || list->last->type == PYRAMID)
		translate_compound(list->last->save, *pars, list->last->type);
	else if (list->last->type == LIGHT)
	{
		save = list->a_light;
		while (save->next)
			save = save->next;
		save->type == 0 ? translation(*pars, &save->pos) :
		ft_pars_exit(*pars, E_PARS);
	}
	free_tab(pars->tab, 3);
}

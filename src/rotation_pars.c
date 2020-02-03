/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 01:26:01 by arraji            #+#    #+#             */
/*   Updated: 2020/02/03 20:11:10 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	rot_obj(t_pars pars, t_obj *obj)
{
	int	type;

	while (obj->next)
		obj = obj->next;
	type = obj->type;
	if (type == SPHERE || type == TRIANGLE)
		ft_pars_exit(pars, E_PARS);
	else if (type == CYLINDER)
		rot(pars, &obj->orient);
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
	if (type == AMB || type == LIGHT || type == 0)
		ft_pars_exit(*pars, E_PARS);
	else if (type == CAM)
		rot(*pars, &list->a_camera->l_at);
	else if (type == OBJ)
		rot_obj(*pars, list->a_obj);
	free_tab(pars->tab, 3);
}

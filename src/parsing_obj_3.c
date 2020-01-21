/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:09:36 by arraji            #+#    #+#             */
/*   Updated: 2020/01/21 00:57:07 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	tr_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	if (ft_tablen(args) != 5)
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1);
	check_tab(args, *pars, 2);
	check_tab(args, *pars, 3);
	check_tab(args, *pars, 4);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = TRIANGLE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &obj->vertex_0);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &obj->vertex_1);
	pars->tab = ft_split(args[3], ',');
	pars_pos(pars, &obj->vertex_2);
	pars->tab = ft_split(args[4], ',');
	pars_color(pars, &obj->color);
}

void	square_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	obj = list->a_obj;
	if (ft_tablen(args) != 5 || !valid_f(args[3]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1);
	check_tab(args, *pars, 2);
	check_tab(args, *pars, 4);
	add_obj(&(list)->a_obj, new_obj());
	while (obj->next)
		obj = obj->next;
	obj->type = SQUARE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &obj->pos);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &obj->norm);
	obj->diam = ft_atof(args[3]);
	pars->tab = ft_split(args[4], ',');
	pars_color(pars, &obj->color);
}

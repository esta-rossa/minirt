/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj_3_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:09:36 by arraji            #+#    #+#             */
/*   Updated: 2020/02/18 01:45:36 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void	tr_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	if (ft_tablen(args) != 5)
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	check_tab(args, *pars, 3, 2);
	check_tab(args, *pars, 4, 1);
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
	obj->sp_type = 0;
	list->last->save = obj;
	list->last->type = OBJ;
}

void	square_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	if (ft_tablen(args) != 5 || !valid_f(args[3]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	check_tab(args, *pars, 4, 1);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = SQUARE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &obj->pos);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &obj->norm);
	obj->norm = vector_norm(obj->norm);
	obj->diam = ft_atof(args[3]);
	pars->tab = ft_split(args[4], ',');
	pars_color(pars, &obj->color);
	obj->sp_type = 0;
	list->last->save = obj;
	list->last->type = OBJ;
}

void	disk_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	if (ft_tablen(args) != 5 || !valid_f(args[3]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	check_tab(args, *pars, 4, 1);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = DISK;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &obj->pos);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &obj->norm);
	obj->norm = vector_norm(obj->norm);
	obj->diam = ft_atof(args[3]);
	pars->tab = ft_split(args[4], ',');
	pars_color(pars, &obj->color);
	obj->sp_type = 0;
	list->last->save = obj;
	list->last->type = OBJ;
}

void	cone_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	if (ft_tablen(args) != 5 || !valid_f(args[3]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	check_tab(args, *pars, 4, 1);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = CONE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &obj->pos);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &obj->orient);
	obj->orient = vector_norm(obj->orient);
	obj->diam = ft_atof(args[3]);
	obj->diam = deg_to_rad(obj->diam);
	pars->tab = ft_split(args[4], ',');
	pars_color(pars, &obj->color);
	obj->cap = 0;
	list->last->save = obj;
	list->last->type = OBJ;
}
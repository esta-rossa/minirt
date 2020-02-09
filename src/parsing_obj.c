/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 02:21:13 by arraji            #+#    #+#             */
/*   Updated: 2020/02/09 23:12:10 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		check_tab(char **args, t_pars pars, int index, int type)
{
	char **tab;

	tab = ft_split(args[index], ',');
	if (ft_tablen(tab) != 3 ||
	args[index][ft_strlen(args[index], 1) - 1] == ',' || args[index][0] == ','
	|| !valid_num(tab[0], type) || !valid_num(tab[1], type) ||
	!valid_num(tab[2], type))
		ft_pars_exit(pars, E_PARS);
	free_tab(tab, 3);
}

void		sp_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	if (ft_tablen(args) != 4)
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	if (!valid_f(args[2]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 3, 1);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = SPHERE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &(obj)->pos);
	obj->radius = ft_atof(args[2]);
	pars->tab = ft_split(args[3], ',');
	pars_color(pars, &(obj)->color);
	list->last->save = obj;
	list->last->type = OBJ;
}

void		plane_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	if (ft_tablen(args) != 4)
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	check_tab(args, *pars, 3, 1);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = PLANE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &obj->pos);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &obj->norm);
	obj->norm = vector_norm(obj->norm);
	pars->tab = ft_split(args[3], ',');
	pars_color(pars, &obj->color);
	list->last->save = obj;
	list->last->type = OBJ;
}

void		cyl_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj *obj;

	if (ft_tablen(args) != 6 || !valid_f(args[3])
	|| !valid_f(args[4]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	check_tab(args, *pars, 5, 1);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = CYLINDER;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &obj->pos);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &obj->orient);
	obj->orient = vector_norm(obj->orient);
	obj->diam = ft_atof(args[3]);
	obj->height = ft_atof(args[4]);
	pars->tab = ft_split(args[5], ',');
	pars_color(pars, &obj->color);
	list->last->save = obj;
	list->last->type = OBJ;
}

void		resul_pars(t_pars *pars, t_all *list, char **args)
{
	if (ft_tablen(args) != 3)
		ft_pars_exit(*pars, E_PARS);
	if (!valid_d(args[1]) || !valid_d(args[2]) ||
	args[1][0] == '-' || args[2][0] == '-')
		ft_pars_exit(*pars, E_PARS);
	if (!(list->wind = (t_wind *)malloc(sizeof(t_wind))))
		ft_exit(E_STD);
	list->wind->wind_x = ft_atoi(args[1]);
	list->wind->wind_y = ft_atoi(args[2]);
	list->wind->wind_x = list->wind->wind_x > 2560 ? 2560 : list->wind->wind_x;
	list->wind->wind_x = list->wind->wind_x < 0 ? 2560 : list->wind->wind_x;
	list->wind->wind_y = list->wind->wind_y > 1395 ? 1395 : list->wind->wind_y;
	list->wind->wind_y = list->wind->wind_y < 0 ? 1395 : list->wind->wind_y;
	list->last->type = AMB;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj_2_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:27:42 by arraji            #+#    #+#             */
/*   Updated: 2020/02/09 02:58:51 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void	cam_pars(t_pars *pars, t_all *list, char **args)
{
	if (ft_tablen(args) != 4 || !valid_d(args[3]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	add_cam(&(list)->a_camera, new_cam());
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &(list->a_camera->pos));
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &(list->a_camera->l_at));
	list->a_camera->l_at = vector_norm(list->a_camera->l_at);
	list->a_camera->fov = ft_atoi(args[3]);
	list->a_camera->default_up = (t_cord){0, 1, 0};
	list->last->save = list->a_camera;
	list->last->type = CAM;
}

void	ambiant_pars(t_pars *pars, t_all *list, char **args)
{
	if (ft_tablen(args) != 3 || !valid_f(args[1]))
		ft_pars_exit(*pars, E_PARS);
	list->phong = (t_phong *)malloc(sizeof(t_phong));
	list->phong->ambient_cof = ft_atof(args[1]);
	pars->tab = ft_split(args[2], ',');
	if (ft_tablen(pars->tab) != 3 || !valid_f(pars->tab[0])
	|| !valid_f(pars->tab[1]) || !valid_f(pars->tab[2]))
		ft_pars_exit(*pars, E_PARS);
	pars_color(pars, &list->phong->ambient_color);
	list->last->save = list->phong;
	list->last->type = AMB;
}

void	light_pars(t_pars *pars, t_all *list, char **args)
{
	t_light	*light;

	if (ft_tablen(args) != 4 || !valid_f(args[2]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 3, 1);
	add_light(&(list)->a_light, new_light());
	light = list->a_light;
	while (light->next)
		light = light->next;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &(light->pos));
	light->bright = ft_atof(args[2]);
	pars->tab = ft_split(args[3], ',');
	pars_color(pars, &(light)->color);
	list->last->save = light;
	list->last->type = LIGHT;
}

void	pars_pos(t_pars *pars, t_cord *pos)
{
	pos->x = ft_atof(pars->tab[0]);
	pos->y = ft_atof(pars->tab[1]);
	pos->z = ft_atof(pars->tab[2]);
	free_tab(pars->tab, 3);
}

void	pars_color(t_pars *pars, t_color *color)
{
	color->r = ft_atof(pars->tab[0]);
	color->g = ft_atof(pars->tab[1]);
	color->b = ft_atof(pars->tab[2]);
	free_tab(pars->tab, 3);
}

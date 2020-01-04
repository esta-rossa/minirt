/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 00:37:42 by arraji            #+#    #+#             */
/*   Updated: 2020/01/04 12:05:13 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_obj(t_obj **alst, t_obj *new)
{
	t_obj *save;

	if (!(*alst))
	{
		(*alst) = new;
		new->next = NULL;
	}
	else
	{
		save = *alst;
		while ((*alst)->next)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
		new->next = NULL;
		*alst = save;
	}
}
void	add_light(t_light **alst, t_light *new)
{
	t_light *save;

	if (!(*alst))
	{
		(*alst) = new;
		new->next = NULL;
	}
	else
	{
		save = *alst;
		while ((*alst)->next)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
		new->next = NULL;
		*alst = save;
	}
}
void	add_cam(t_camera **alst, t_camera *new)
{
	t_camera *save;

	if (!(*alst))
	{
		(*alst) = new;
		new->next = new;
		new->previous = new;
		(*alst) = new;
	}
	else
	{
		save = (*alst)->next;
		(*alst)->next = new;
		new->previous = *alst;
		new->next = save;
		save->previous = new;
		(*alst) = new;
	}
}

t_obj	*new_obj(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!new)
		ft_exit(E_STD);
	new->next = NULL;
	return (new);
}

t_camera	*new_cam(void)
{
	t_camera	*new;

	new = (t_camera *)malloc(sizeof(t_camera));
	if (!new)
		ft_exit(E_STD);
	new->next = NULL;
	return (new);
}

t_light	*new_light(void)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
		ft_exit(E_STD);
	new->next = NULL;
	return (new);
}

double	ft_atof(char *str)
{
	return (atof(str));
}
void free_tab(char **tab, int i)
{
	i--;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}
void	cam_check(char **args, t_pars pars)
{
	char **pos;
	char **vec;

	if (ft_tablen(args) != 4)
		ft_pars_exit(pars, E_PARS);
	pos = ft_split(args[1], ',');
	if (ft_tablen(pos) != 3 || !valid_f(pos[0])
	|| !valid_f(pos[1]) || !valid_f(pos[2]))
		ft_pars_exit(pars, E_PARS);
	vec = ft_split(args[2], ',');
	if (ft_tablen(vec) != 3 || !valid_f(vec[0])
	|| !valid_f(vec[1]) || !valid_f(vec[2]))
		ft_pars_exit(pars, E_PARS);
	if (!valid_f(args[3]))
		ft_pars_exit(pars, E_PARS);
	free_tab(vec, 3);
	free_tab(pos, 3);
}

void	light_check(char **args, t_pars pars)
{
	char **pos;
	char **color;
	if (ft_tablen(args) != 4)
		ft_pars_exit(pars, E_PARS);
	pos = ft_split(args[1], ',');
	if (ft_tablen(pos) != 3 || !valid_f(pos[0])
	|| !valid_f(pos[1]) || !valid_f(pos[2]))
		ft_pars_exit(pars, E_PARS);
	if (!valid_f(args[2]))
		ft_pars_exit(pars, E_PARS);
	color = ft_split(args[3], ',');
	if (ft_tablen(color) != 3 || !valid_f(color[0])
	|| !valid_f(color[1]) || !valid_f(color[2]))
		ft_pars_exit(pars, E_PARS);
	free_tab(color, 3);
	free_tab(pos, 3);
}

void	check_sp(char **args, t_pars pars)
{
	char **pos;
	char **color;

	if (ft_tablen(args) != 4)
		ft_pars_exit(pars, E_PARS);
	pos = ft_split(args[1], ',');
	if (ft_tablen(pos) != 3 || !valid_f(pos[0])
	|| !valid_f(pos[1]) || !valid_f(pos[2]))
		ft_pars_exit(pars, E_PARS);
	if (!valid_f(args[2]))
		ft_pars_exit(pars, E_PARS);
	color = ft_split(args[3], ',');
	if (ft_tablen(color) != 3 || !valid_f(color[0])
	|| !valid_f(color[1]) || !valid_f(color[2]))
		ft_pars_exit(pars, E_PARS);
	free_tab(color, 3);
	free_tab(pos, 3);
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

void	sp_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	*obj;

	check_sp(args, *pars);
	add_obj(&(list)->a_obj, new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = SPHERE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &(obj)->pos);
	obj->ray = ft_atof(args[2]);
	pars->tab = ft_split(args[3], ',');
	pars_color(pars, &(obj)->color);
}

void	cam_pars(t_pars *pars, t_all *list, char **args)
{
	cam_check(args, *pars);
	add_cam(&(list)->a_camera, new_cam());
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &(list->a_camera->pos));
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &(list->a_camera->l_at));
	list->a_camera->fov = ft_atof(args[3]);
}

void	light_pars(t_pars *pars, t_all *list, char **args)
{
	t_light	*light;

	light_check(args, *pars);
	add_light(&(list)->a_light, new_light());
	light = list->a_light;
	while (light->next)
		light= light->next;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &(light->pos));
	light->bright = ft_atof(args[2]);
	pars->tab = ft_split(args[3], ',');
	pars_color(pars, &(light)->color);
}

void	line_pars(t_pars *pars, t_all *list, char **args)
{
	if (ft_strncmp(args[0], "sp", 3) == 0)
		sp_pars(pars, list, args);
	else if (ft_strncmp(args[0], "c", 3) == 0)
		cam_pars(pars, list, args);
	else if (ft_strncmp(args[0], "l", 3) == 0)
		light_pars(pars, list, args);
	else
		ft_pars_exit(*pars, E_PARS);
}


void	data_read(t_pars *pars, t_all *all)
{
	char	**args;
	t_all	*list;
	int		res;

	res = 1;
	while (res == 1)
	{
		res = get_next_line(pars->fd, &(pars)->line);
		if (res == -1)
			ft_exit(E_STD);
		args = ft_split(pars->line, ' ');
		if (ft_tablen(args) > 0)
		{
			list = all;
			line_pars(pars, list, args);
		}
		free_tab(args, ft_tablen(args));
		free(pars->line);
	}
}

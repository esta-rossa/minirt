/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 00:37:42 by arraji            #+#    #+#             */
/*   Updated: 2020/01/01 01:48:26 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
void	check_sp(char **args, t_pars pars)
{
	char **pos;
	char **color;

	if (ft_tablen(args) != 4)
		ft_exit(pars, E_PARS);
	pos = ft_split(args[1], ',');
	if (ft_tablen(pos) != 3 || !valid_f(pos[0])
	|| !valid_f(pos[1]) || !valid_f(pos[2]))
		ft_exit(pars, E_PARS);
	if (!valid_f(args[2]))
		ft_exit(pars, E_PARS);
	color = ft_split(args[3], ',');
	if (ft_tablen(color) != 3 || !valid_f(color[0])
	|| !valid_f(color[1]) || !valid_f(color[2]))
		ft_exit(pars, E_PARS);
	free_tab(color, 3);
	free_tab(pos, 3);
}

void	pars_pos(t_pars *pars, t_obj *obj)
{
	obj->position.x = ft_atof(pars->tab[0]);
	obj->position.y = ft_atof(pars->tab[1]);
	obj->position.z = ft_atof(pars->tab[2]);
	free_tab(pars->tab, 3);
}

void	pars_color(t_pars *pars, t_obj *obj)
{
	obj->color.r = ft_atof(pars->tab[0]);
	obj->color.b = ft_atof(pars->tab[1]);
	obj->color.g = ft_atof(pars->tab[2]);
	free_tab(pars->tab, 3);
}

void	sp_pars(t_pars *pars, t_obj *obj, char **args)
{
	check_sp( args, *pars);
	obj->type = SPHERE;
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, obj);
	obj->ray = ft_atof(args[2]);
	pars->tab = ft_split(args[3], ',');
	pars_color(pars, obj);
}

void	line_pars(t_pars *pars, t_obj *obj, char **args)
{

	if (ft_strncmp(args[0], "sp", 10) == 0)
	{
		sp_pars(pars, obj, args);
	}
	else
		ft_exit(*pars, E_PARS);

}

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

t_obj	*new_obj(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	data_read(t_pars *pars, t_obj **obj)
{
	char	**args;
	t_obj	*list;
	t_save	*save;

	while (get_next_line(pars->fd, &(pars)->line) > 0)
	{
		add_obj(obj, new_obj());
		list = *obj;
		while (list->next)
			list = list->next;
		args = ft_split(pars->line, ' ');
		line_pars(pars, list, args);
	}

}

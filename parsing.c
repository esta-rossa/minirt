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

void	sp_pars(t_pars *pars, t_obj *obj, char **args)
{
	obj->type = SPHERE;
	pars->tab = ft_split(args[1], ',');
	if (ft_tablen(pars->tab) != 3 || !valid_f(pars->tab[0])
	|| !valid_f(pars->tab[1]) || !valid_f(pars->tab[2]))
		ft_exit(*pars, E_PARS);

}

void	line_pars(t_pars *pars, t_obj *obj, char **args)
{

	if (ft_strncmp(args[0], "sp", 10) == 0)
	{
		sp_pars(pars, obj, args);
	}
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

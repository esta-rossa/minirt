/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:23:43 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 20:20:22 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

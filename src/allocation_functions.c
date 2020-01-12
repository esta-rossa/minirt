/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:12:52 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 14:15:56 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light		*new_light(void)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
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

t_obj		*new_obj(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!new)
		ft_exit(E_STD);
	new->next = NULL;
	return (new);
}

void		free_tab(char **tab, int i)
{
	i--;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

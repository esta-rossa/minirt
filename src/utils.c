/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:29:41 by arraji            #+#    #+#             */
/*   Updated: 2020/01/20 02:04:48 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	smallest_double(double *tab, int size)
{
	int		index;
	int		jndex;
	double	save;

	index = -1;
	while (++index < size)
		if (tab[index] < 0)
			tab[index] = FAR;
	index = -1;
	while (index < size)
	{
		jndex = index + 1;
		while (jndex < size)
		{
			if (tab[jndex] < tab[index])
			{
				save = tab[index];
				tab[index] = tab[jndex];
				tab[jndex] = save;
			}
			jndex++;
		}
		index++;
	}
	return (tab[0]);
}

void		pr_cord(t_cord cord, char *name, char *end)
{
	printf("%s.x: %f %s.y: %f %s.z: %f%s", name, cord.x, name, cord.y, name, cord.z, end);
}

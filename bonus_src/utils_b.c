/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:29:41 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 04:38:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

double	smallest_double(double *tab, int size)
{
	int		index;
	int		jndex;
	double	save;

	index = -1;
	while (++index < size)
		if (tab[index] < 0)
			tab[index] = FAR;
	index = 0;
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

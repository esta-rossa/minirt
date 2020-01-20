/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:25:03 by arraji            #+#    #+#             */
/*   Updated: 2020/01/20 04:41:53 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	line_pars(t_pars *pars, t_all *list, char **args)
{
	if (ft_strncmp(args[0], "sp", 2) == 0)
		sp_pars(pars, list, args);
	else if (ft_strncmp(args[0], "c", 2) == 0)
		cam_pars(pars, list, args);
	else if (ft_strncmp(args[0], "l", 1) == 0)
		light_pars(pars, list, args);
	else if (ft_strncmp(args[0], "A", 1) == 0)
		ambiant_pars(pars, list, args);
	else if (ft_strncmp(args[0], "R", 1) == 0)
		resul_pars(pars, list, args);
	else if (ft_strncmp(args[0], "pl", 2) == 0)
		plane_pars(pars, list, args);
	else if (ft_strncmp(args[0], "cy", 2) == 0)
		cyl_pars(pars, list, args);
	else if (ft_strncmp(args[0], "tr", 2) == 0)
		tr_pars(pars, list, args);
	else if (ft_strncmp(args[0], "sq", 2) == 0)
		square_pars(pars, list, args);
	else
		ft_pars_exit(*pars, E_PARS);
}

void	data_read(t_pars *pars, t_all *all)
{
	char	**args;
	t_all	*list;
	int		res;

	res = 1;
	pars->line_num = 0;
	while (res == 1)
	{
		res = get_next_line(pars->fd, &(pars)->line);
		if (res == -1)
			ft_exit(E_STD);
		pars->line_num++;
		args = ft_split(pars->line, ' ');
		if (ft_tablen(args) > 0 && ft_strncmp(args[0] , ".", 1) != 0 && args[0][0] != '.')
		{
			list = all;
			line_pars(pars, list, args);
		}
		free_tab(args, ft_tablen(args));
		free(pars->line);
	}
}

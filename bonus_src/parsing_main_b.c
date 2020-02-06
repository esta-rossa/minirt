/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:25:03 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 12:15:15 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void	line_pars(t_pars *pars, t_all *list, char **args)
{
	if (ft_strncmp(args[0], "sp", 3) == 0)
		sp_pars(pars, list, args);
	else if (ft_strncmp(args[0], "c", 2) == 0)
		cam_pars(pars, list, args);
	else if (ft_strncmp(args[0], "l", 2) == 0)
		light_pars(pars, list, args);
	else if (ft_strncmp(args[0], "A", 2) == 0)
		ambiant_pars(pars, list, args);
	else if (ft_strncmp(args[0], "R", 2) == 0)
		resul_pars(pars, list, args);
	else if (ft_strncmp(args[0], "pl", 3) == 0)
		plane_pars(pars, list, args);
	else if (ft_strncmp(args[0], "cy", 3) == 0)
		cyl_pars(pars, list, args);
	else if (ft_strncmp(args[0], "sq", 3) == 0)
		square_pars(pars, list, args);
	else if (ft_strncmp(args[0], "rot", 4) == 0)
		rot_pars(pars, list, args);
	else if (ft_strncmp(args[0], "tr", 3) == 0)
		tr_pars(pars, list, args);
	else if (ft_strncmp(args[0], "tran", 5) == 0)
		tran_pars(pars, list, args);
	else if (ft_strncmp(args[0], "cu", 3) == 0)
		cube_pars(pars, list, args);
	else if (ft_strncmp(args[0], "py", 3) == 0)
		pyramid_pars(pars, list, args);
	else if (ft_strncmp(args[0], "di", 3) == 0)
		disk_pars(pars, list, args);
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
		if (ft_tablen(args) > 0 && args[0][0] != '.')
		{
			list = all;
			line_pars(pars, list, args);
		}
		free_tab(args, ft_tablen(args));
		free(pars->line);
	}
}

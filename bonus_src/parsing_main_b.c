/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:25:03 by arraji            #+#    #+#             */
/*   Updated: 2020/02/22 12:06:46 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	assign_functions(
void (*parsing_funcs[15])(t_pars *pars, t_all *list, char **args))
{
	parsing_funcs[0] = sp_pars;
	parsing_funcs[1] = cam_pars;
	parsing_funcs[2] = light_pars;
	parsing_funcs[3] = ambiant_pars;
	parsing_funcs[4] = resul_pars;
	parsing_funcs[5] = plane_pars;
	parsing_funcs[6] = cyl_pars;
	parsing_funcs[7] = square_pars;
	parsing_funcs[8] = rot_pars;
	parsing_funcs[9] = tr_pars;
	parsing_funcs[10] = tran_pars;
	parsing_funcs[11] = cube_pars;
	parsing_funcs[12] = pyramid_pars;
	parsing_funcs[13] = disk_pars;
	parsing_funcs[14] = cone_pars;
}

static	char	**get_args(void)
{
	char	**args;

	args = (char **)malloc(19 * sizeof(char *));
	args[0] = "sp";
	args[1] = "c";
	args[2] = "l";
	args[3] = "A";
	args[4] = "R";
	args[5] = "pl";
	args[6] = "cy";
	args[7] = "sq";
	args[8] = "rot";
	args[9] = "tr";
	args[10] = "tran";
	args[11] = "cu";
	args[12] = "py";
	args[13] = "di";
	args[14] = "co";
	args[15] = "AA";
	args[16] = "F";
	args[17] = "COL";
	args[18] = "STR";
	return (args);
}

void			line_pars(t_pars *pars, t_all *list, char **args)
{
	int		index;
	char	**param;
	void	(*parsing_funcs[14])(t_pars *pars, t_all *list, char **args);

	index = -1;
	param = get_args();
	assign_functions(parsing_funcs);
	while (++index < NUM_OF_ARGS)
		if (ft_strncmp(args[0], param[index],
		ft_strlen(param[index], 1) + 1) == 0)
		{
			index < 15 ? parsing_funcs[index](pars, list, args) : 1;
			index == 15 ? list->aa = 1 : 1;
			index == 16 ? list->filter = 1 : 1;
			index == 17 ? list->color = 1 : 1;
			index == 18 ? list->str = 1 : 1;
			free(param);
			return ;
		}
	free(param);
	ft_pars_exit(*pars, E_PARS);
}

void			data_read(t_pars *pars, t_all *all)
{
	char	**args;
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
			line_pars(pars, all, args);
		free_tab(args, ft_tablen(args));
		free(pars->line);
	}
}

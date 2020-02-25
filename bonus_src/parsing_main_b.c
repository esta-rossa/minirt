/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:25:03 by arraji            #+#    #+#             */
/*   Updated: 2020/02/24 16:59:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	assign_functions(
void (*parsing_funcs[16])(t_pars *pars, t_all *list, char **args))
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
	parsing_funcs[15] = uv_sp_pars;
}

static	char	**get_args(void)
{
	char	**param;

	param = (char **)malloc(20 * sizeof(char *));
	param[0] = "sp";
	param[1] = "c";
	param[2] = "l";
	param[3] = "A";
	param[4] = "R";
	param[5] = "pl";
	param[6] = "cy";
	param[7] = "sq";
	param[8] = "rot";
	param[9] = "tr";
	param[10] = "tran";
	param[11] = "cu";
	param[12] = "py";
	param[13] = "di";
	param[14] = "co";
	param[15] = "usp";
	param[16] = "AA";
	param[17] = "F";
	param[18] = "COL";
	param[19] = "STR";
	return (param);
}

void			line_pars(t_pars *pars, t_all *list, char **args)
{
	int		index;
	char	**param;
	void	(*parsing_funcs[16])(t_pars *pars, t_all *list, char **args);

	index = -1;
	param = get_args();
	assign_functions(parsing_funcs);
	while (++index < NUM_OF_ARGS)
		if (ft_strncmp(args[0], param[index],
		ft_strlen(param[index], 1) + 1) == 0)
		{
			index < 16 ? parsing_funcs[index](pars, list, args) : 1;
			index == 16 ? list->aa = 1 : 1;
			index == 17 ? list->filter = 1 : 1;
			index == 18 ? list->color = 1 : 1;
			index == 19 ? list->str = 1 : 1;
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
		if (ft_tablen(args) > 0)
			line_pars(pars, all, args);
		free_tab(args, ft_tablen(args));
		free(pars->line);
	}
}

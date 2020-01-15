/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:54:20 by arraji            #+#    #+#             */
/*   Updated: 2020/01/15 01:02:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_pars_exit(t_pars pars, int number)
{
	char *color;

	color = PRINT_GR;
	if (number != 0)
	{
		color = PRINT_RED;
		ft_printf("%sERROR%s %d : ", color, RESET, number);
		number == E_STD ? perror("") : 1;
		number == E_ARGS ? ft_printf("argument given are %d\n", pars.argc - 1)
		: 1;
		number == E_ND_FILE ?
		ft_printf("second argument\'%s\' is not \'--save\'\n", pars.argv[2])
		: 1;
		number == E_NO_FILE ? ft_printf("Can't open file \'%s\'\n"
		, pars.argv[1]) : 1;
		number == E_FILE_FRM ? ft_printf("wrong file format\n") : 1;
		number == E_PARS ?
		ft_printf("invalid data in line %d\n", pars.line_num) : 1;
		number == E_NO_CAM ? ft_printf("No camera giving\n") : 1;
		number == E_NO_RES ? ft_printf("resolution are not giving\n") : 1;
		exit(number);
	}
}

void	ft_exit(int number)
{
	char *color;

	color = PRINT_GR;
	if (number != 0)
	{
		color = PRINT_RED;
		ft_printf("%sERROR%s %d : ", color, RESET, number);
		number == E_STD ? perror("") : 1;
	}
}

void	init_error(t_pars pars)
{
	int index;

	index = ft_strlen(pars.argv[1], 1);
	if (!(pars.argc >= 2 && pars.argc <= 3))
		ft_pars_exit(pars, E_ARGS);
	if (pars.argc == 3 && ft_strncmp(pars.argv[2], "--save", 100) != 0)
		ft_pars_exit(pars, E_ND_FILE);
	if (pars.fd < 0)
		ft_pars_exit(pars, E_NO_FILE);
	while (pars.argv[1][index] != '.' && index > 0)
		index--;
	if (index == 0 || ft_strncmp(&(pars).argv[1][index], ".rt", 5) != 0)
		ft_pars_exit(pars, E_FILE_FRM);
}

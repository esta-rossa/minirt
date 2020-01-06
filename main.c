/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:24:23 by arraji            #+#    #+#             */
/*   Updated: 2020/01/06 03:52:50 by arraji           ###   ########.fr       */
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
		number == E_PARS ? ft_printf("invalid data\n") : 1;
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

void	init_all(t_all *all)
{
	all->wind = (t_wind *) malloc(sizeof(t_wind));
	all->phong = (t_phong *) malloc(sizeof(t_phong));
}

int main(int argc, char **argv)
{
	t_pars	pars;
	t_all	all;

	all = (t_all){NULL, NULL, NULL, NULL, NULL};
	pars.fd = open(argv[1], O_RDONLY);
	pars.argc = argc;
	pars.argv = argv;
	init_error(pars);
	init_all(&all);
	data_read(&pars, &all);
	here_we_go(&all);
	mlx_loop(all.wind->init);
	// key_hook(key_press); if (button == LEFT_KEY) akdasd asdl
	ft_pars_exit(pars, 0);
}


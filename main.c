/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:24:23 by arraji            #+#    #+#             */
/*   Updated: 2020/01/01 00:55:15 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>
void	ft_exit(t_pars pars, int number)
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

void	init_error(t_pars pars)
{
	int index;

	index = ft_strlen(pars.argv[1], 1);
	if (!(pars.argc >= 2 && pars.argc <= 3))
		ft_exit(pars, E_ARGS);
	if (pars.argc == 3 && ft_strncmp(pars.argv[2], "--save", 100) != 0)
		ft_exit(pars, E_ND_FILE);
	if (pars.fd < 0)
		ft_exit(pars, E_NO_FILE);
	while (pars.argv[1][index] != '.' && index > 0)
		index--;
	if (index == 0 || ft_strncmp(&(pars).argv[1][index], ".rt", 5) != 0)
		ft_exit(pars, E_FILE_FRM);
}

int main(int argc, char **argv)
{
	int		fd;
	t_obj	*obj;
	t_pars	pars;

	obj = NULL;
	pars.fd = open(argv[1], O_RDONLY);
	pars.argc = argc;
	pars.index = 0;
	pars.argv = argv;
	init_error(pars);
	data_read(&pars, &obj);
	while (obj)
	{
	printf("%d", obj->type);
	obj = obj->next;
	}
	ft_exit(pars, 0);
}


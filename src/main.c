/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:24:23 by arraji            #+#    #+#             */
/*   Updated: 2020/02/03 17:17:05 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_all(t_all *all, t_pars pars)
{
	all->last = (t_last *)malloc(sizeof(t_last));
	all->last->type = 0;
	if (pars.argc == 3 && ft_strncmp(pars.argv[2], "--save", 6) == 0)
		all->save = 1;
}

void	check_after_pars(t_all *all, t_pars pars)
{
	if (all->wind == NULL)
		ft_pars_exit(pars, E_NO_RES);
	if (all->a_camera == NULL)
		ft_pars_exit(pars, E_NO_CAM);
	if (all->phong == NULL)
		ft_pars_exit(pars, E_NO_AMB);
	all->a_camera = all->a_camera->next;
}

int		main(int argc, char **argv)
{
	t_pars	pars;
	t_all	all;

	all = (t_all){NULL, NULL, NULL, NULL, NULL, NULL, 0};
	pars.fd = open(argv[1], O_RDONLY);
	pars.argc = argc;
	pars.argv = argv;
	init_error(pars);
	init_all(&all, pars);
	data_read(&pars, &all);
	check_after_pars(&all, pars);
	init_wind(all);
	here_we_go(&all);
	hook(all);
}

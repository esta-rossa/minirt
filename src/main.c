/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:24:23 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 20:21:47 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_all(t_all *all)
{
	all->phong = (t_phong *)malloc(sizeof(t_phong));
}

int		main(int argc, char **argv)
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

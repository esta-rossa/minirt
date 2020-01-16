/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:24:23 by arraji            #+#    #+#             */
/*   Updated: 2020/01/16 18:39:01 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_all(t_all *all)
{
	all->phong = (t_phong *)malloc(sizeof(t_phong));
}

void	check_after_pars(t_all all, t_pars pars)
{
	if (all.wind == NULL)
		ft_pars_exit(pars, E_NO_RES);
	if (all.a_camera == NULL)
		ft_pars_exit(pars, E_NO_CAM);
}

int		die()
{
	exit(0);
	return (0);
}

int		control(int button, t_all *all)
{
	// printf("%d", button);
	if (button == KEY_LEFT)
	{
		mlx_destroy_image(all->wind->init, all->wind->img_p);
		printf("%f\n", all->a_camera->pos.x);
		all->a_camera = all->a_camera->previous;
		printf("LEFT PRESSED\n");
		here_we_go(all);
	}
	else if (button == KEY_RIGHT)
	{
		mlx_destroy_image(all->wind->init, all->wind->img_p);
		printf("%f\n" , all->a_camera->pos.x);
		all->a_camera = all->a_camera->next;
		printf("RIGHT PRESSED\n");
		here_we_go(all);
	}
	else if (button == KEY_ESC)
	{
		die();
	}
	return (0);
}


void	hook(t_all all)
{
	mlx_hook(all.wind->wind_p, 17, 0, die, NULL);
	mlx_key_hook(all.wind->wind_p, control, &all);
	mlx_loop(all.wind->init);
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
	check_after_pars(all, pars);
	init_wind(all);
	here_we_go(&all);
	hook(all);
	// key_hook(key_press); if (button == LEFT_KEY) akdasd asdl
	ft_pars_exit(pars, 0);
}

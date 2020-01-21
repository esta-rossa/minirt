/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:53:59 by arraji            #+#    #+#             */
/*   Updated: 2020/01/21 00:53:10 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		die(void)
{
	exit(0);
	return (0);
}

int		control(int button, t_all *all)
{
	if (button == KEY_LEFT)
	{
		mlx_destroy_image(all->wind->init, all->wind->img_p);
		all->a_camera = all->a_camera->previous;
		here_we_go(all);
	}
	else if (button == KEY_RIGHT)
	{
		mlx_destroy_image(all->wind->init, all->wind->img_p);
		all->a_camera = all->a_camera->next;
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
	if (all.save == 0)
	{
		mlx_hook(all.wind->wind_p, 17, 0, die, NULL);
		mlx_key_hook(all.wind->wind_p, control, &all);
		mlx_loop(all.wind->init);
	}
}

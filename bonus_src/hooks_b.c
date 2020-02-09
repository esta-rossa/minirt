/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:53:59 by arraji            #+#    #+#             */
/*   Updated: 2020/02/09 17:07:02 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

int		die(void)
{
	exit(0);
	return (0);
}

int		is_pressed(int button)
{
	if (button == KEY_EIGHT || button == KEY_TWO || button == KEY_FOUR ||
	button == KEY_SEX || button == KEY_UP || button == KEY_DOWN ||
	button == KEY_NINE || button == KEY_SEVEN
	|| button == KEY_ONE || button == KEY_THREE)
		return (1);
	return (0);
}

int		control(int button, t_all *all)
{
	if (button == KEY_P)
	{
		mlx_destroy_image(all->wind->init, all->wind->img_p);
		all->a_camera = all->a_camera->previous;
		here_we_go(all);
	}
	else if (button == KEY_N)
	{
		mlx_destroy_image(all->wind->init, all->wind->img_p);
		all->a_camera = all->a_camera->next;
		here_we_go(all);
	}
	else if (button == KEY_ESC)
		die();
	else if (button == KEY_SPACE)
		all->rot = all->rot == 1 ? 0 : 1;
	else if (is_pressed(button))
	{
		all->rot == 0 ? camera_tran(all->a_camera, button) : 1;
		all->rot == 1 ? camera_rot(all->a_camera, button) : 1;
		mlx_destroy_image(all->wind->init, all->wind->img_p);
		here_we_go(all);
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

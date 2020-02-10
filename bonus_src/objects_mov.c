/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_mov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:49:44 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 17:51:36 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

int		get_obj(int button, int x, int y, t_all *all)
{
	double	t;

	t = FAR;
	if (button == 1)
	{
		all->a_camera->v_ray =
		get_ray(*all->a_camera, all->a_camera->bot, x, all->wind->wind_y - y);
		if ((all->pos = inters(all->a_obj, *all->a_camera, &t)) >= 0)
			all->cam = 0;
		else
			all->cam = 1;
	}
	if (button == 2)
		all->cam = 1;
	return (0);
}

void	object_rot_midleware(t_obj *obj, t_camera cam, int pos, int key)
{
	while (pos-- > 0)
		obj = obj->next;
	if (key == KEY_EIGHT)
		object_rot(obj, cam.right);
	else if (key == KEY_TWO)
		object_rot(obj, vector_mltp(cam.right, -1));
	else if (key == KEY_FOUR)
		object_rot(obj, cam.up);
	else if (key == KEY_SEX)
		object_rot(obj, vector_mltp(cam.up, -1));
}

void	object_trans_midleware(t_obj *obj, t_camera camera, int pos, int button)
{
	while (pos-- > 0)
		obj = obj->next;
	if (button == KEY_EIGHT)
		object_trans(obj, camera.up);
	else if (button == KEY_TWO)
		object_trans(obj, vector_mltp(camera.up, -1));
	else if (button == KEY_FOUR)
		object_trans(obj, vector_mltp(camera.right, -1));
	else if (button == KEY_SEX)
		object_trans(obj, camera.right);
	else if (button == KEY_UP)
		object_trans(obj, camera.l_at);
	else if (button == KEY_DOWN)
		object_trans(obj, vector_mltp(camera.l_at, -1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mov_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 02:44:56 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 00:07:02 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

void	camera_tran(t_camera *cam, int key)
{
	if (key == KEY_EIGHT)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->up, 5));
	else if (key == KEY_TWO)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->up, -5));
	else if (key == KEY_FOUR)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->right, -5));
	else if (key == KEY_SEX)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->right, 5));
	else if (key == KEY_UP)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->l_at, 5));
	else if (key == KEY_DOWN)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->l_at, -5));
	else if (key == KEY_NINE)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, 5), vector_mltp(cam->right, 5)));
	else if (key == KEY_SEVEN)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, 5), vector_mltp(cam->right, -5)));
	else if (key == KEY_ONE)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, -5), vector_mltp(cam->right, -5)));
	else if (key == KEY_THREE)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, -5), vector_mltp(cam->right, 5)));
}

/*
**[0]: y->x
**[1]: x->z
*/

t_cord	rodrigues_rot(t_cord vec, t_cord rot ,double angle)
{
	t_cord	new;
	t_cord	cross;
	double	dot;

	cross = cross_prod(rot, vec);
	dot = dot_pr(vec, rot);
	new.x = (vec.x * cos(angle)) + (cross.x * sin(angle)) +
	(rot.x * dot * (1 - cos(angle)));
	new.y = (vec.y * cos(angle)) + (cross.y * sin(angle)) +
	(rot.y * dot * (1 - cos(angle)));
	new.z = (vec.z * cos(angle)) + (cross.z * sin(angle)) +
	(rot.z * dot * (1 - cos(angle)));
	return (new);
}

void	camera_rot(t_camera *cam, int key)
{
	static	double	angles[2];
	static	int		step = 0;

	cam->l_at = vector_norm(cam->l_at);
	if (!step)
	{
		angles[0] = acos(dot_pr(cam->l_at, (t_cord){1, 0, 0}));
		angles[1] = acos(dot_pr(cam->l_at, (t_cord){0, 1, 0}));
		step = 1;
	}
	if (key == KEY_EIGHT)
		cam->l_at = rodrigues_rot(cam->l_at, cam->right, (-M_PI / 8));
	else if (key == KEY_TWO)
		cam->l_at = rodrigues_rot(cam->l_at, cam->right, (M_PI / 8));
	else if (key == KEY_FOUR)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, -(M_PI / 8));
	else if (key == KEY_SEX)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, M_PI / 8);
	else if (key == KEY_UP)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, M_PI);
}

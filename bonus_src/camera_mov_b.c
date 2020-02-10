/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mov_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 02:44:56 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 11:06:34 by arraji           ###   ########.fr       */
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

void	camera_rot(t_camera *cam, int key)
{
	cam->l_at = vector_norm(cam->l_at);
	if (key == KEY_EIGHT)
		cam->l_at = rodrigues_rot(cam->l_at, cam->right, (-M_PI / 8));
	else if (key == KEY_TWO)
		cam->l_at = rodrigues_rot(cam->l_at, cam->right, (M_PI / 8));
	else if (key == KEY_FOUR)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, -(M_PI / 8));
	else if (key == KEY_SEX)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, M_PI / 8);
	else if (key == KEY_THREE)
		cam->l_at = rodrigues_rot(cam->l_at,
		vector_add(cam->up, cam->right), M_PI / 8);
	else if (key == KEY_ONE)
		cam->l_at = rodrigues_rot(cam->l_at,
		vector_add(vector_mltp(cam->up, -1), cam->right), M_PI / 8);
	else if (key == KEY_NINE)
		cam->l_at = rodrigues_rot(cam->l_at,
		vector_add(cam->up, vector_mltp(cam->right, -1)), M_PI / 8);
	else if (key == KEY_SEVEN)
		cam->l_at = rodrigues_rot(cam->l_at, vector_add(
		vector_mltp(cam->up, -1), vector_mltp(cam->right, -1)), M_PI / 8);
	else if (key == KEY_UP)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, M_PI);
}

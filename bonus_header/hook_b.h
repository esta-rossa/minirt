/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_b.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:10:52 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 17:52:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HOOK_H
# define FT_HOOK_H
# include "minirt_b.h"
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_ESC		53
# define KEY_N			45
# define KEY_P			35
# define KEY_SPACE		49
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_ONE		83
# define KEY_TWO		84
# define KEY_THREE		85
# define KEY_FOUR		86
# define KEY_FIVE		87
# define KEY_SEX		88
# define KEY_SEVEN		89
# define KEY_EIGHT		91
# define KEY_NINE		92
# define MOUSE_LEFT		1
int		die();
void	camera_tran(t_camera *camera, int key);
void	camera_rot(t_camera *cam, int key);
int		control(int button, t_all *all);
void	hook(t_all all);
void	object_trans_midleware(t_obj *obj, t_camera camera, int pos, int button);
void	object_rot_midleware(t_obj *obj, t_camera camera, int pos, int button);
int		get_obj(int button, int x, int y, t_all *all);
void	object_rot(t_obj *obj, t_cord vec);
void	object_trans(t_obj *obj, t_cord vec);
#endif

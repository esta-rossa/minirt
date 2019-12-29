/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 02:58:58 by arraji            #+#    #+#             */
/*   Updated: 2019/12/29 18:22:30 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAMERA_H
# define FT_CAMERA_H
#include "minirt.h"

t_cord	get_ray(t_camera camera, t_cord bo_left, double x, double y);
t_cord	init_camera(t_camera *camera);
#endif

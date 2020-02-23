/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_b.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 02:58:58 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:36:27 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAMERA_B_H
# define FT_CAMERA_B_H
# include "minirt_b.h"

t_cord	get_ray(t_camera camera, t_cord bo_left, double x, double y);
void	init_camera(t_camera *camera, t_all all);
#endif

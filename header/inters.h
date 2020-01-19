/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:45:28 by arraji            #+#    #+#             */
/*   Updated: 2020/01/17 02:13:33 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERS_H
# define FT_INTERS_H
#include "minirt.h"
int		sp_inters(t_obj o, t_camera camera, double *t);
int		plan_inters(t_obj o, t_camera camera, double *t);
int		inters(t_obj *obj, t_camera camera, double *t);
int		cyl_inters_init(t_obj *o, t_camera camera, t_cyl_needs *need);
int		disk_iners(t_obj o, t_camera camera, double *t);
int		cyl_inters(t_obj *o, t_camera camera, double *t);
void	cyl_norm(t_obj *o, t_camera camera, t_cyl_needs need, int dir);
void	put_cap(t_obj *o, t_camera camera, double *t);
void	cyl_calcul(t_obj *o, t_camera camera, t_cyl_needs *need);
int		triangle_inters(t_obj *o, t_camera camera, double *t);
#endif

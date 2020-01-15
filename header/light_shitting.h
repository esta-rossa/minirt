/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shitting.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:59:36 by arraji            #+#    #+#             */
/*   Updated: 2020/01/14 09:33:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIGHT_SHITTING_H
# define FT_LIGHT_SHITTING_H
# include "minirt.h"
void		ft_phong(t_all all, t_obj *obj, t_color *color, double t);
void		get_diffuse(t_all *all, t_obj *obj);
void		get_speculare(t_all *all);
void		get_ambiant(t_all *all, t_obj *obj);
void		init_sp(t_all all, t_obj *obj, double t);
void		init_plan(t_all all, t_obj *obj, double t);
void		init_cyl(t_all all, t_obj *obj, double t);
void		init_phong(t_all all, t_obj *obj, double t);
#endif

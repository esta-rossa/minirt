/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shitting_b.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:59:36 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:37:12 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIGHT_SHITTING_B_H
# define FT_LIGHT_SHITTING_B_H
# include "minirt_b.h"

void		ft_phong(t_all all, t_obj obj, t_color *color, double t);
void		init_phong(t_all all, t_obj *obj, double t);
void		init_cone(t_all all, t_obj *obj, double t);
#endif

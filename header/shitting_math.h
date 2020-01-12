/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shitting_math.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:51:13 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 19:08:33 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHITTING_MATH_H
# define FT_SHITTING_MATH_H
# include "minirt.h"
void		set_cord(t_cord *point, double x, double y, double z);
double		dot_pr(t_cord u, t_cord v);
double		deg_to_rad(double deg);
int			cmp_float(double a, double b);
double		ft_atof(char *str);
#endif

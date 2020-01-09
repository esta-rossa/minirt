/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:35:13 by arraji            #+#    #+#             */
/*   Updated: 2020/01/09 20:01:39 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
#include <fcntl.h>
# include "libft/libft.h"
# include "vector_op.h"
# include "struct.h"
# include "matrix.h"
# include "camera.h"
# include "colors.h"
# include "error.h"
# include "parsing.h"
# define FAR 1e30
# define CLOSE 1e-6
# define vibe_check write(1,"v",1);
void	pr_cord(t_cord cord, char *name, char *end);


t_cord		*new_point(double x, double y, double z);
double		distance(t_cord a, t_cord b);
void		set_cord(t_cord *point, double x, double y, double z);
t_cord		*new_point(double x, double y, double z);
double		twod_func(double a, double b, double c);
void		circle(t_cord o, double ray, void *init, void *wind);
void		draw_line(t_cord a, t_cord b, void *init, void* wind);
void		set_vector(t_cord *vector ,t_cord a, t_cord b);
double		dot_pr(t_cord u, t_cord v);
double		deg_to_rad(double deg);
void		here_we_go(t_all *all);
int			cmp_float(double a, double b);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:35:13 by arraji            #+#    #+#             */
/*   Updated: 2019/12/16 04:52:49 by arraji           ###   ########.fr       */
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
# include "libft/libft.h"
# include "vector_op.h"
# define vibe_check write(1,"v",1);

typedef struct	s_cord
{
	double x;
	double y;
	double z;
}				t_cord;

typedef struct	s_sphere
{
	t_cord	centre;
	double	ray;
}				t_sphere;

typedef	struct	s_wind
{
	void *init;
	void *wind_p;
	int wind_x;
	int wind_y;
}				t_wind;

typedef	struct	s_line
{
	double xa;
	double xb;
	double ya;
	double yb;
	double za;
	double zb;
}				t_line;

typedef	struct	s_object
{
	t_cord camera;
	t_cord curr;
	t_cord v_ray;
	t_sphere sphere;

}				t_obj;
t_cord		*new_point(double x, double y, double z);
double		distance(t_cord a, t_cord b);
void		set_cord(t_cord *point, double x, double y, double z);
t_cord		*new_point(double x, double y, double z);
double		twod_func(double a, double b, double c);
void		circle(t_cord o, double ray, void *init, void *wind);
void		draw_line(t_cord a, t_cord b, void *init, void* wind);
void		set_vector(t_cord *vector ,t_cord a, t_cord b);
double		dot_pr(t_cord u, t_cord v);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 05:26:55 by arraji            #+#    #+#             */
/*   Updated: 2019/12/19 06:07:27 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

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

typedef	struct	s_matrix
{
	double	**mtrx;
	int		row;
	int		column;
}				t_matrix;

#endif

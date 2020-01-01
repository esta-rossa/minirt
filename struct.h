/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 05:26:55 by arraji            #+#    #+#             */
/*   Updated: 2019/12/31 17:40:16 by arraji           ###   ########.fr       */
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

typedef	struct	s_color
{
	int		r;
	int		b;
	int		g;
}				t_color;

typedef struct	s_sphere
{
	t_cord	centre;
	double	ray;
	t_color	color;
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

/* typedef	struct	s_object
{
	t_cord camera;
	t_cord curr;
	t_cord v_ray;
	t_sphere sphere;
	t_sphere sphere2;

}				t_obj; */

typedef	struct	s_matrix
{
	double	**mtrx;
	int		row;
	int		column;
}				t_matrix;

typedef	struct	s_ray
{
	t_matrix	direct;
	t_matrix	orig;
}				t_ray;

typedef	struct	s_camera
{
	t_cord			position;
	t_cord			l_at;
	t_cord			up;
	t_cord			right;
	t_cord			x_inc;
	t_cord			y_inc;
	double			fov;
	double			distance;
	unsigned	int	x_reso;
	unsigned	int	y_reso;
}				t_camera;

typedef	struct	s_obj
{
	int					type;
	t_cord				position;
	t_color				color;
	double				ray;
	struct	s_obj		*next;
}				t_obj;

typedef	struct	s_pars
{
	int		argc;
	char	**argv;
	char	**args;
	char	**tab;
	int		fd;
	char	*line;
	char	*invalid;
	int		index;
}				t_pars;

typedef	struct	s_save
{
	void	*head;
	void	*last;
	int		size;
}				t_save;
#endif

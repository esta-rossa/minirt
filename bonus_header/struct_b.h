/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_b.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 05:26:55 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:41:37 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_B_H
# define FT_STRUCT_B_H
# include "minirt_b.h"

typedef struct	s_cord
{
	double x;
	double y;
	double z;
}				t_cord;

typedef	struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef	struct	s_wind
{
	int		check;
	void	*init;
	void	*wind_p;
	int		wind_x;
	int		wind_y;
	void	*img_p;
	int		*img_data;
}				t_wind;

typedef	struct	s_camera
{
	t_cord				pos;
	t_cord				l_at;
	t_cord				default_up;
	t_cord				up;
	t_cord				right;
	t_cord				x_inc;
	t_cord				y_inc;
	t_cord				p_inter;
	double				fov;
	t_cord				v_ray;
	t_cord				bot;
	int					cap;
	unsigned	int		x_reso;
	unsigned	int		y_reso;
	struct s_camera		*next;
	struct s_camera		*previous;
}				t_camera;

typedef	struct	s_obj
{
	int					type;
	t_cord				pos;
	t_cord				vertex_0;
	t_cord				vertex_1;
	t_cord				vertex_2;
	t_cord				norm;
	t_color				color;
	t_cord				orient;
	int					cap;
	double				diam;
	double				height;
	struct s_obj		*head;
	int					sp_type;
	struct s_obj		*next;

}				t_obj;

typedef	struct	s_pars
{
	int		argc;
	char	**argv;
	char	**tab;
	int		fd;
	char	*line;
	int		line_num;
	int		index;
}				t_pars;

typedef	struct	s_tr_needs
{
	double	dot_of_cros;
	t_cord	cros_ray_vec2;
	t_cord	cros_vec1_sub;
	double	check;
	double	check2;
	t_cord	sub_ori_ver1;
	t_cord	vec_1;
	t_cord	vec_2;
}				t_tr_needs;
typedef	struct	s_cyl_needs
{
	double	m[2];
	double	t[2];
	double	vars[4];
}				t_cyl_needs;

typedef	struct	s_light
{
	t_cord			pos;
	t_color			color;
	t_cord			reflect;
	t_cord			vec;
	double			bright;
	int				type;
	struct s_light	*next;
}				t_light;

typedef	struct	s_phong
{
	t_color	diffuse;
	t_color	speculare;
	t_color	ambient;
	t_color	ambient_color;
	double	ambient_cof;
}				t_phong;

typedef	struct	s_last
{
	void	*save;
	int		type;
}				t_last;

typedef	struct	s_all
{
	t_camera	*a_camera;
	t_obj		*a_obj;
	t_light		*a_light;
	t_wind		*wind;
	t_phong		*phong;
	t_last		*last;
	int			save;
	int			rot;
	int			aa;
	int			cam;
	int			pos;
	int			filter;
	int			color;
	int			str;
}				t_all;
#endif

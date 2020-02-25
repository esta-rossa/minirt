/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_b.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:35:13 by arraji            #+#    #+#             */
/*   Updated: 2020/02/25 00:36:08 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_B_H
# define FT_MINIRT_B_H
# define FAR 1e30
# define NEAR 1e-6
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include "libft.h"
# include "struct_b.h"
# include "vector_op_b.h"
# include "camera_b.h"
# include "colors_b.h"
# include "error_b.h"
# include "parsing_b.h"
# include "inters_b.h"
# include "shitting_math_b.h"
# include "light_shitting_b.h"
# include "shadows_b.h"
# include "hook_b.h"
# include "save_b.h"
# include "thread_b.h"
# include "filter_b.h"
# include "stereoscopy_b.h"
# include "mlx.h"
# include "texture_b.h"

void		load_texture(t_all all, t_texture *texture);
t_color		get_pixel_at(t_texture *texture, double x, double y);
void		render(t_all all, t_camera s_camera, t_color *color, t_cord v_ray);
void		here_we_go(t_all *all);
void		get_all_rays(t_cord *v_rays, double x, double y);
void		render_all_ray(t_color *colors, t_cord *v_rays);
void		get_pixel(int *indexs, int *img);
void		init_wind(t_all all);
void		init_image(t_all all);
double		smallest_double(double *tab, int size);
void		put_image(t_all *all);
t_all		*g_all;
#endif

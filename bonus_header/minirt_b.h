/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_b.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:35:13 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 05:22:09 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H
# define FAR 1e30
# define NEAR 1e-6
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
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
# define vibe_check write(1, "v", 1);
void		render(t_all all, t_camera s_camera, t_color *color);
void		here_we_go(t_all *all);
void		pr_cord(t_cord cord, char *name, char *end);
void		init_wind(t_all all);
void		init_image(t_all all);
double		smallest_double(double *tab, int size);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:35:13 by arraji            #+#    #+#             */
/*   Updated: 2020/01/19 20:09:09 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H
# define FAR 1e30
# define NEAR 1e-6
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define vibe_check write(1,"v",1);
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"
# include "vector_op.h"
# include "struct.h"
# include "matrix.h"
# include "camera.h"
# include "colors.h"
# include "error.h"
# include "parsing.h"
# include "inters.h"
# include "shitting_math.h"
# include "light_shitting.h"
# include "shadows.h"
# include "save.h"
# include "hook.h"

void		render(t_all all, t_camera s_camera, t_color *color);
void		here_we_go(t_all *all);
void		pr_cord(t_cord cord, char *name, char *end);
void		init_wind(t_all all);
void		init_image(t_all all);
double		smallest_double(double *tab, int size);
#endif

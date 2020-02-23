/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_b.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 02:08:56 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:36:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_B_H
# define FT_COLORS_B_H
# include "minirt_b.h"
# define PRINT_RED		"\033[1;31m"
# define PRINT_GR		"\033[1;32m"
# define RESET			"\033[0m"

void		clamp_color(t_color *col, int min, int max);
t_color		color_add(t_color color_a, t_color color_b);
int			get_int(t_color *col);
t_color		color_mltp(t_color color, double num);
t_color		get_color(int color);
#endif

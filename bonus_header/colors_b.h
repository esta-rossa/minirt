/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_b.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 02:08:56 by arraji            #+#    #+#             */
/*   Updated: 2020/02/08 11:26:30 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H
# include "minirt_b.h"
# define PRINT_RED		"\033[1;31m"
# define PRINT_GR		"\033[1;32m"
# define RESET			"\033[0m"

void		clamp_color(t_color *col, int min, int max);
int			get_color(t_color *col);
t_color		color_mltp(t_color color, double num);
#endif

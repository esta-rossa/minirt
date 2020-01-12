/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 02:08:56 by arraji            #+#    #+#             */
/*   Updated: 2020/01/12 18:55:18 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H
# define PRINT_RED		"\033[1;31m"
# define PRINT_GR		"\033[1;32m"
# define RESET			"\033[0m"

void		clamp_color(t_color *col, int min, int max);
int			get_color(t_color col);
t_color		color_mltp(t_color color, double num);
#endif

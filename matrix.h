/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 06:22:47 by arraji            #+#    #+#             */
/*   Updated: 2019/12/19 07:40:44 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# include "minirt.h"

int		creat_matrix(t_matrix *mtx, int row, int column);
int		cmp_float(double a, double b);
void	set_matrix(t_matrix *matrix, int row, int column, double value);
int		cmp_matrix(t_matrix matrix_a, t_matrix matrix_b);
#endif

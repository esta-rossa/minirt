/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 06:22:47 by arraji            #+#    #+#             */
/*   Updated: 2019/12/20 11:36:28 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# include "minirt.h"

int			creat_matrix(t_matrix *mtx, int row, int column);
int			cmp_float(double a, double b);
void		set_matrix(t_matrix *matrix, int row, int column, double value);
int			cmp_matrix(t_matrix matrix_a, t_matrix matrix_b);
int			mult_matrix(t_matrix *new_mtx, t_matrix mtx_a, t_matrix mtx_b);
void		mtx_fill(t_matrix *matrix, double value);
t_matrix	copy_matrix(t_matrix matrix);
void		transp_matrix(t_matrix *matrix);
double		determinant(t_matrix matrice);
t_matrix	submatrixe(t_matrix matrix, int del_row, int del_column);
#endif

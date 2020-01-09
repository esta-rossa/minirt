/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 06:22:47 by arraji            #+#    #+#             */
/*   Updated: 2020/01/09 06:24:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# include "minirt.h"

int			creat_matrix(t_matrix *mtx, int row, int column);
void		set_matrix(t_matrix *matrix, int row, int column, double value);
int			cmp_matrix(t_matrix matrix_a, t_matrix matrix_b);
t_matrix	mult_matrix(t_matrix mtx_a, t_matrix mtx_b);
void		mtx_fill(t_matrix *matrix, double value);
t_matrix	copy_matrix(t_matrix matrix);
void		transp_matrix(t_matrix *matrix);
double		determinant(t_matrix matrice);
t_matrix	submatrix(t_matrix matrix, int del_row, int del_column);
double		matrix_minor(t_matrix matrix, int row, int column);
double		cofactors(t_matrix matrix, int row, int column);
t_matrix	inversion(t_matrix matrix);
t_matrix	mult_tuple(t_matrix matrix, t_matrix tuple);
t_matrix	indentity_mtx();
t_matrix	translation(double x, double y, double z);
t_matrix	m_vecteur(double x, double y, double z);
t_matrix	m_point(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	rotation_x(double radiant);
t_matrix	rotation_y(double radiant);
t_matrix	rotation_z(double radiant);
#endif

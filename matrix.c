/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:35:21 by arraji            #+#    #+#             */
/*   Updated: 2019/12/25 20:57:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
** matrix[row][column]
*/

int		creat_matrix(t_matrix *mtx, int row, int column)
{
	double	**new_mtrx;
	int		r;
	int		c;

	r = 0;
	mtx->column = column;
	mtx->row = row;
	if (!(new_mtrx = (double **)malloc(sizeof(double **) * row)))
		return (-1);
	while (r < row)
	{
		c = 0;
		while (c < column)
		{
			if (!(new_mtrx[r] = (double *)malloc(sizeof(double *) * column)))
				return (-1);
			c++;
		}
		r++;
	}
	mtx->mtrx = new_mtrx;
	mtx_fill(mtx, 0);
	return (1);
}

int		cmp_float(double a, double b)
{
	double result;

	result = (a < b) ? b - a : a - b;
	if (result > 0.00001)
		return (0);
	return (1);
}

void	set_matrix(t_matrix *matrix, int row, int column, double value)
{
	matrix->mtrx[row][column] = value;
}

int		cmp_matrix(t_matrix matrix_a, t_matrix matrix_b)
{
	int		row;
	int		column;

	row = 0;
	while (row < matrix_a.row)
	{
		column = 0;
		while (column < matrix_a.column)
		{
			if (cmp_float(matrix_a.mtrx[row][column],
			matrix_b.mtrx[row][column]) == 0)
				return (0);
			column++;
		}
		row++;
	}
	return (1);
}

void	mtx_fill(t_matrix *matrix, double value)
{
	int row;
	int column;

	row = 0;
	while (row < matrix->row)
	{
		column = 0;
		while (column < matrix->column)
		{
			matrix->mtrx[row][column] = value;
			column++;
		}
		row++;
	}
}

t_matrix		mult_matrix(t_matrix mtx_a, t_matrix mtx_b)
{
	int			row;
	int			column;
	int			lst_row;
	int			lst_column;
	t_matrix	new_mtx;

	lst_row = 0;
	creat_matrix(&new_mtx, mtx_a.row, mtx_a.column);
	while (lst_row < mtx_a.row)
	{
		lst_column = 0;
		while (lst_column < mtx_a.column)
		{
			row = 0;
			column = 0;
			while (row < mtx_a.row)
			{
				new_mtx.mtrx[lst_row][lst_column] +=
				mtx_a.mtrx[row++][lst_column] * mtx_b.mtrx[lst_row][column++];
			}
			lst_column++;
		}
		lst_row++;
	}
	return (new_mtx);
}

t_matrix	copy_matrix(t_matrix matrix)
{
	t_matrix	new_matrix;
	int			row;
	int			column;

	new_matrix.row = matrix.row;
	new_matrix.column = matrix.column;
	creat_matrix(&new_matrix, matrix.row, matrix.column);
	row = 0;
	while (row < matrix.row)
	{
		column = 0;
		while (column < matrix.column)
		{
			new_matrix.mtrx[row][column] = matrix.mtrx[row][column];
			column++;
		}
		row++;
	}
	return (new_matrix);
}

void		transp_matrix(t_matrix *matrix)
{
	t_matrix	copy;
	int			row;
	int			column;

	row = 0;
	copy = copy_matrix(*matrix);
	while (row < copy.row)
	{
		column = 0;
		while (column < copy.column)
		{
			matrix->mtrx[column][row] = copy.mtrx[row][column];
			column++;
		}
		row++;
	}
}

double		determinant(t_matrix matrix)
{
	double	det;
	int		column;

	if (matrix.row <= 2)
	{
		det = matrix.mtrx[0][0] * matrix.mtrx[1][1] -
		matrix.mtrx[0][1] * matrix.mtrx[1][0];
	}
	else
	{
		column = 0;
		det = 0;
		while (column < matrix.column)
		{
			det += matrix.mtrx[0][column] * cofactors(matrix, 0, column);
			column++;
		}
	}
	return (det);
}

t_matrix	submatrix(t_matrix matrix, int del_row, int del_column)
{
	t_matrix	new_matrix;
	int			row;
	int			column;
	int			new_row;
	int			new_column;

	row = 0;
	new_row = 0;
	creat_matrix(&new_matrix, matrix.row - (matrix.row > del_row)
	, matrix.column - (matrix.column > del_column));
	while (row < matrix.row)
	{
		column = 0;
		new_column = 0;
		while (column < matrix.column)
		{
			if (column != del_column && row != del_row)
				new_matrix.mtrx[new_row][new_column++] =
				matrix.mtrx[row][column];
			column++;
		}
		if (row++ != del_row)
			new_row++;
	}
	return (new_matrix);
}

double		matrix_minor(t_matrix matrix, int row, int column)
{
	t_matrix	new_matrix;
	double		det;

	new_matrix = submatrix(matrix, row, column);
	det = determinant(new_matrix);
	return (det);
}

double		cofactors(t_matrix matrix, int row, int column)
{
	t_matrix	new_matrix;
	double		det;
	int			sign;

	new_matrix = submatrix(matrix, row, column);
	det = determinant(new_matrix);
	sign = ((row - column) % 2) == 0 ? 1 : -1;
	return (det * sign);
}

t_matrix	inversion(t_matrix matrix)
{
	t_matrix	inverted;
	double		det;
	int			row;
	int			column;

	det = determinant(matrix);
	creat_matrix(&inverted, matrix.row, matrix.column);
	row = 0;
	while (row < matrix.row)
	{
		column = 0;
		while (column < matrix.column)
		{
			inverted.mtrx[row][column] = cofactors(matrix, row, column) / det;
			column++;
		}
		row++;
	}
	transp_matrix(&inverted);
	return (inverted);
}

t_matrix	mult_tuple(t_matrix matrix, t_matrix tuple)
{
	t_matrix	new_tuple;
	int			row;
	int			column;

	row = 0;
	creat_matrix(&new_tuple, 4, 1);
	mtx_fill(&new_tuple, 0);
	while (row < matrix.row)
	{
		column = 0;
		while (column < matrix.column)
		{
			new_tuple.mtrx[row][0] += matrix.mtrx[row][column]
			* tuple.mtrx[column][0];
			column++;
		}
		row++;
	}
	return (new_tuple);
}

t_matrix	indentity_mtx(void)
{
	t_matrix	new_identity;
	int			row;
	int			column;

	creat_matrix(&new_identity, 4, 4);
	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			new_identity.mtrx[row][column] = (row == column) ? 1 : 0;
			column++;
		}
		row++;
	}
	return (new_identity);
}

t_matrix	translation(double x, double y, double z)
{
	t_matrix	new_matrix;

	new_matrix = indentity_mtx();
	new_matrix.mtrx[0][3] = x;
	new_matrix.mtrx[1][3] = y;
	new_matrix.mtrx[2][3] = z;
	return (new_matrix);
}

t_matrix	point(double x, double y, double z)
{
	t_matrix	new_tuple;

	creat_matrix(&new_tuple, 4, 1);
	new_tuple.mtrx[0][0] = x;
	new_tuple.mtrx[1][0] = y;
	new_tuple.mtrx[2][0] = z;
	new_tuple.mtrx[3][0] = 1;
	return (new_tuple);
}

t_matrix	vecteur(double x, double y, double z)
{
	t_matrix	new_tuple;

	creat_matrix(&new_tuple, 4, 1);
	new_tuple.mtrx[0][0] = x;
	new_tuple.mtrx[1][0] = y;
	new_tuple.mtrx[2][0] = z;
	new_tuple.mtrx[3][0] = 0;
	return (new_tuple);
}

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	new_matrix;

	new_matrix = indentity_mtx();
	new_matrix.mtrx[0][0] = x;
	new_matrix.mtrx[1][1] = y;
	new_matrix.mtrx[2][2] = z;
	return (new_matrix);
}

t_matrix	rotation_x(double radiant)
{
	t_matrix	new_matrix;

	new_matrix = indentity_mtx();
	new_matrix.mtrx[1][1] = cos(radiant);
	new_matrix.mtrx[2][2] = cos(radiant);
	new_matrix.mtrx[2][1] = sin(radiant);
	new_matrix.mtrx[1][2] = -sin(radiant);
	return (new_matrix);
}

t_matrix	rotation_y(double radiant)
{
	t_matrix	new_matrix;

	new_matrix = indentity_mtx();
	new_matrix.mtrx[0][0] = cos(radiant);
	new_matrix.mtrx[0][2] = sin(radiant);
	new_matrix.mtrx[2][0] = -sin(radiant);
	new_matrix.mtrx[2][2] = cos(radiant);
	return (new_matrix);
}

t_matrix	rotation_z(double radiant)
{
	t_matrix	new_matrix;

	new_matrix = indentity_mtx();
	new_matrix.mtrx[0][0] = cos(radiant);
	new_matrix.mtrx[0][1] = -sin(radiant);
	new_matrix.mtrx[1][0] = sin(radiant);
	new_matrix.mtrx[1][1] = cos(radiant);
	return (new_matrix);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:35:21 by arraji            #+#    #+#             */
/*   Updated: 2019/12/20 12:03:22 by arraji           ###   ########.fr       */
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

int		mult_matrix(t_matrix *new_mtx, t_matrix mtx_a, t_matrix mtx_b)
{
	int			row;
	int			column;
	int			lst_row;
	int			lst_column;

	lst_row = 0;
	mtx_fill(new_mtx, 0);
	while (lst_row < mtx_a.row)
	{
		lst_column = 0;
		while (lst_column < mtx_a.column)
		{
			row = 0;
			column = 0;
			while (row < mtx_a.row)
			{
				new_mtx->mtrx[lst_row][lst_column] +=
				mtx_a.mtrx[row][lst_column] * mtx_b.mtrx[lst_row][column];
				row++;
				column++;
			}
			lst_column++;
		}
		lst_row++;
	}
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

	det = matrix.mtrx[0][0] * matrix.mtrx[1][1] -
	matrix.mtrx[0][1] * matrix.mtrx[1][0];
	return (det);
}

t_matrix	submatrixe(t_matrix matrix, int del_row, int del_column)
{
	t_matrix	new_matrix;
	int			row;
	int			column;
	int			new_row;
	int			new_column;

	row = 0;
	new_row = 0;
	creat_matrix(&new_matrix, matrix.row - 1, matrix.column - 1);
	while (row < matrix.row)
	{
		column = 0;
		new_column = 0;
		while (column < matrix.column)
		{
			if (column != del_column && row != del_row)
			{
				new_matrix.mtrx[new_row][new_column] =
				matrix.mtrx[row][column];
				new_column++;

			}
			column++;
		}
		if (row != del_row)
			new_row++;
		row++;
	}
	return (new_matrix);
}
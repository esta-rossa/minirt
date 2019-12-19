/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:35:21 by arraji            #+#    #+#             */
/*   Updated: 2019/12/19 07:41:30 by arraji           ###   ########.fr       */
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

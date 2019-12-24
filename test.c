#include "minirt.h"
#include <stdarg.h>

int	main(int c, char **v)
{
	t_matrix mtx;
	t_matrix mtx2;
	t_matrix mtx3;
	t_matrix tuple;
	creat_matrix(&tuple, 4, 1);
	creat_matrix(&mtx, 4, 4);
	// creat_matrix(&mtx2, 3, 3);
	creat_matrix(&mtx3, 4, 4);
	set_matrix(&mtx, 0, 0, 1);
	set_matrix(&mtx, 0, 1, 2);
	set_matrix(&mtx, 0, 2, 3);
	set_matrix(&mtx, 0, 3, 4);
	set_matrix(&mtx, 1, 0, 2);
	set_matrix(&mtx, 1, 1, 4);
	set_matrix(&mtx, 1, 2, 4);
	set_matrix(&mtx, 1, 3, 2);
	set_matrix(&mtx, 2, 0, 8);
	set_matrix(&mtx, 2, 1, 6);
	set_matrix(&mtx, 2, 2, 4);
	set_matrix(&mtx, 2, 3, 1);
	set_matrix(&mtx, 3, 0, 0);
	set_matrix(&mtx, 3, 1, 0);
	set_matrix(&mtx, 3, 2, 0);
	set_matrix(&mtx, 3, 3, 1);
	for (size_t i = 0; i < tuple.row; i++)
	{
		for (size_t j = 0; j < tuple.column; j++)
		{
			scanf("%lf", &tuple.mtrx[i][j]);
		}
	}
	for (size_t i = 0; i < tuple.row; i++)
	{
		for (size_t j = 0; j < tuple.column; j++)
		{
			printf("%f ", tuple.mtrx[i][j]);
		}
		printf("\n");

	}
	tuple = mult_tuple(indentity_mtx(), tuple);
	for (size_t i = 0; i < tuple.row; i++)
	{
		for (size_t j = 0; j < tuple.column; j++)
		{
			printf("%f ", tuple.mtrx[i][j]);
		}
		printf("\n");

	}
	mtx2 = copy_matrix(mtx);
	transp_matrix(&mtx2);
	mtx3 =indentity_mtx();
	for (size_t i = 0; i < mtx.row; i++)
	{
		for (size_t j = 0; j < mtx.column; j++)
		{
			printf("%f ", mtx.mtrx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
/* 	mtx = inversion(mtx);
	for (size_t i = 0; i < mtx.row; i++)
	{
		for (size_t j = 0; j < mtx.column; j++)
		{
			printf("%f ", mtx.mtrx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n"); */
	for (size_t i = 0; i <mtx2.row; i++)
	{
		for (size_t j = 0; j < mtx2.column; j++)
		{
			printf("%f ", mtx2.mtrx[i][j]);
		}
		printf("\n");
	}
	printf ("%d\n\n\n", cmp_matrix(mtx, mtx2));
	for (size_t i = 0; i < mtx3.row; i++)
	{
		for (size_t j = 0; j < mtx3.column; j++)
		{
			printf("%f ", mtx3.mtrx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	mtx3 = mult_matrix(mtx3, inversion(mtx));
	for (size_t i = 0; i < mtx3.row; i++)
	{
		for (size_t j = 0; j < mtx3.column; j++)
		{
			printf("%f ", mtx3.mtrx[i][j]);
		}
		printf("\n");
	}
	printf("%f",determinant(mtx));
}

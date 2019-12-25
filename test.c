#include "minirt.h"
#include <stdarg.h>

void pr_matrix(t_matrix matrix)
{
	for (size_t i = 0; i < matrix.row; i++)
	{
		for (size_t j = 0; j < matrix.column; j++)
		{
			printf("%f ", matrix.mtrx[i][j]);
		}
		printf("\n");
	}
}
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
	/* for (size_t i = 0; i < tuple.row; i++)
	{
		for (size_t j = 0; j < tuple.column; j++)
		{
			scanf("%lf", &tuple.mtrx[i][j]);
		}
	} */
	tuple = vecteur(1, 2, 3);
	printf("tuple\n");
		pr_matrix(tuple);
	tuple = mult_tuple(rotation_x(M_PI * 2), tuple);
	printf("tuple\n");
		pr_matrix(tuple);
	mtx2 = copy_matrix(mtx);
	transp_matrix(&mtx2);
	printf("mtx\n");
		pr_matrix(mtx);
	printf("\n");
	printf("\n");
	printf("mtx2\n");
		pr_matrix(mtx2);
	mtx3 = mult_matrix(mtx, mtx2);
	printf("mtx3\n");
		pr_matrix(mtx3);
	printf("\n");
	printf("\n");
	mtx3 = submatrix(mtx3, 0,0);
	pr_matrix(mtx3);
	printf("%f",determinant(mtx));
}

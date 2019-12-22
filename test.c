#include "minirt.h"
#include <stdarg.h>

int	main(int c, char **v)
{
	t_matrix mtx;
	t_matrix mtx2;
	t_matrix mtx3;
	creat_matrix(&mtx, 3, 3);
	creat_matrix(&mtx2, 3, 3);
	creat_matrix(&mtx3, 3, 3);
	set_matrix(&mtx, 0, 0, 1);
	set_matrix(&mtx, 0, 1, 2);
	set_matrix(&mtx, 0, 2, 3);
	set_matrix(&mtx, 1, 0, 3);
	set_matrix(&mtx, 1, 1, 4);
	set_matrix(&mtx, 1, 2, 5);
	set_matrix(&mtx, 2, 0, 6);
	set_matrix(&mtx, 2, 1, 7);
	set_matrix(&mtx, 2, 2, 8);


	/* set_matrix(&mtx2, 0, 0, 0);
	set_matrix(&mtx2, 0, 1, 1);
	set_matrix(&mtx2, 0, 2, 2);
	set_matrix(&mtx2, 1, 0, 3);
	set_matrix(&mtx2, 1, 1, 4);
	set_matrix(&mtx2, 1, 2, 5);
	set_matrix(&mtx2, 2, 0, 6);
	set_matrix(&mtx2, 2, 1, 7);
	set_matrix(&mtx2, 2, 2, 8); */
	mtx2 = copy_matrix(mtx);
	mult_matrix(&mtx3, mtx, mtx2);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			 printf("%f ", mtx.mtrx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			 printf("%f ", mtx2.mtrx[i][j]);
		}
		printf("\n");
	}
	printf ("%d\n\n\n", cmp_matrix(mtx, mtx2));
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			 printf("%f ", mtx3.mtrx[i][j]);
		}
		printf("\n");
	}
}

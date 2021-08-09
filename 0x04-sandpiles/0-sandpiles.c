#include <stdlib.h>
#include <stdio.h>

/**
 * grid_addition - add 2 grids
 * @grid1: first matrix
 * @grid2: second matrix
 */

void grid_addition(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * grid_print - print a grid
 * @grid: matrix
 */

void grid_print(int grid[3][3])
{
	int i = 0;
	int j = 0;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_is_ok - check if a grid is ok
 * @grid: matrix
 * Return: 1 if is ok or 0 if not
 */

int grid_is_ok(int grid[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * grid_change - change a grid value
 * @grid1: matrix
 */

void grid_change(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int gridx[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			gridx[i][j] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1) >= 0 && (i - 1) < 3)
					gridx[i - 1][j] += 1;
				if ((j - 1) >= 0 && (j - 1) < 3)
					gridx[i][j - 1] += 1;
				if ((i + 1) >= 0 && (i + 1) < 3)
					gridx[i + 1][j] += 1;
				if ((j + 1) >= 0 && (j + 1) < 3)
					gridx[i][j + 1] += 1;
			}
		}
	}
	grid_addition(grid1, gridx);
}

/**
 * sandpiles_sum - sum 2 sandpiles
 * @grid1: first matrix
 * @grid2: second matrix
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_addition(grid1, grid2);
	while (!grid_is_ok(grid1))
	{
		grid_print(grid1);
		grid_change(grid1);
	}
}

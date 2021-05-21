#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 *stableCheck - check if a sandpile is stable
 *@grid: 3x3 grid
 *
 *Return: 1 if stable, 0 otherwise
 */
int stableCheck(int grid[3][3])
{
	int i, j;

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
 * topplingRound - makes a toppling round
 * @grid: 3x3 grid
 *
 */

void topplingRound(int grid[3][3])
{
	int i, j;
	int cpGrid[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cpGrid[i][j] = grid[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (cpGrid[i][j] >= 4)
			{
				if (i + 1 < 3)
					grid[i + 1][j] = grid[i + 1][j] + 1;
				if (i - 1 > -1)
					grid[i - 1][j] = grid[i - 1][j] + 1;
				if (j + 1 < 3)
					grid[i][j + 1] = grid[i][j + 1] + 1;
				if (j - 1 > -1)
					grid[i][j - 1] = grid[i][j - 1] + 1;
				grid[i][j] = grid[i][j] - 4;
			}
		}
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (stableCheck(grid1) != 1)
	{
		printf("=\n");
		print_grid(grid1);
		topplingRound(grid1);
	}

}

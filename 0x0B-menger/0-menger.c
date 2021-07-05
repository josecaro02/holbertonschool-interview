#include "menger.h"
#include "math.h"
#include <stdio.h>

/**
 *menger - main function
 *@level: level of the menger
 *
 *Return: nothing, its a void
 */
void menger(int level)
{
	int i, j, h, k, limit, check;

	if (level < 0)
		return;

	for (i = 0, limit = pow(3, level); i < limit; i++)
	{
		for (j = 0; j < limit; j++ )
		{
			check = 1;
			h = i;
			k = j;
			while (h != 0 && k != 0)
			{
				if (h % 3 == 1  && k % 3 == 1)
				{
					check = 0;
					break;
				}
				h = h / 3;
				k = k / 3;
			}
			if (check == 1)
				printf("%c", '#');
			else
				printf("%c", ' ');
		}
		printf("\n");
	}
}

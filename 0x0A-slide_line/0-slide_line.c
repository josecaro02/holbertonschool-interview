#include "slide_line.h"

/**
 * merge - slide the line
 * @line: array with numbers to merge
 * @move: type of move, left or right
 * @i: value of the line
 * @start: begging of the line in the direction given
 * @current: Current value
 * @index: index of the current value
 * @empty: number of fields a value could move
 *
 * Return: its a void functions
 */

void merge(int *line, int move, int i, int start, int *current, int *index, int *empty)
{
	if (line[i] == 0)
		*empty += 1;

	if (i == start && line[i] != 0)
	{
		*current = line[i];
		*index = i;
	}

	if (line[i] != 0 && line[i] == *current && i != start)
	{
		line[*index] += line[i];
		line[i] = 0;
		*current = 0;
		*empty += 1;
	}

	if (line[i] != 0 && *current != line[i] && i != start)
	{
		line[i - (*empty * move)] = line[i];
		*current = line[i];
		*index = i - (*empty * move);
		if (*empty)
			line[i] = 0;
	}
}
/**
 * slide_line - Slide & merge an array of integers to left or right
 * @line: array with numbers to merge
 * @size: number of elements in the line
 * @direction: direction to merge the number in the line
 *
 * Return: 1 success. 0 otherwise
 */

int slide_line(int *line, size_t size, int direction)
{
	int i, move, index, empty, start, current;
	int sizeArray = (int) size;

	if (!line || (direction != 0 && direction != 1))
		return (0);

	current = empty = 0;

	if (direction == 0)
		move = 1;
	else
		move = -1;

	if (direction == 0)
	{
		for (i = start = index = 0; i < sizeArray; i++)
		{
			merge(line, move, i, start, &current, &index, &empty);
		}
		
	}
	else
	{
		for (i = start = index = sizeArray - 1; i >= 0; i--)
		{
			merge(line, move, i, start, &current, &index, &empty);
		}
	}

	return (1);
}


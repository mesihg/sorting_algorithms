#include "sort.h"


/**
 * swap - swaps the given inputs
 *@a: integer input one
 *@b: integer input two
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *selection_sort - sort an array of integers using selection sort
 *@array: array of integers
 *@size: size of the integers
 *Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}

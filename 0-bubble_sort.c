#include "sort.h"

/**
 * bubble_sort - sort an array in ascending order
 *@array: input array of integers
 *@size: size of the array
  *Return: void
  */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				size_t temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}

		}

	}

}

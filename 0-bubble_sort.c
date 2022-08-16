#include "sort.h"

/**
 * bubble_sort - sort an array in ascending order
 *@array: input array of integers
 *@size: size of the array
  *Return: void
  */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}

		}

	}

}

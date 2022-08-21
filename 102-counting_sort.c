#include "sort.h"

/**
 * counting_sort - sorts array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max, j, *count_array, *sorted_arr;
	size_t i;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = calloc((max + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j < max; j++)
	{
		count_array[j + 1] += count_array[j];
	}
	print_array(count_array, max + 1);
	sorted_arr = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		sorted_arr[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_arr[i];
	}
	free(sorted_arr);
	free(count_array);
}

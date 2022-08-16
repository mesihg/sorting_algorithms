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
 * partition - find partition position
 * @arr: array of integers
 * @low: lowest point of the partition
 * @high: highest point of the partition
 * @size: size of the array
 *
 * Return: point of the partition
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	if (i != j)
		print_array(arr, size);
	return (i);
}
/**
 * quicksort - sorts a partition of an array of integers
 * @array: array of integers
 * @low: lowest point of the partition
 * @high: highest point of the partition
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);

	}
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

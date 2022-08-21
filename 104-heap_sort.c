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
 * heapify - convert to binary heap
 * @array: arrays of integers
 * @size: size of the array
 * @base: index of the base row in the tree
 * @root: root node of the binary tree
 * Return: void
 */

void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

/**
 * heap_sort - sorts the integers in ascending order
 * @array: arrays of integers
 * @size: size of integers
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}

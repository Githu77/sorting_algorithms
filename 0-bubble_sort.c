#include "sort.h"

/**
* bubble_sort - sorts integers by bubbling the big numbers to the right
* @array: integers
* @size: array size
*
*
*
*
*
*
*
*
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, x;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

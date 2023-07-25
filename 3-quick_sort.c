#include "sort.h"

void divide(int beg, int pivot, int *i, size_t size);
int partition(int beg, int pivot, int *i, size_t size);
void swap_int(int *a, int *b);
/**
 * quick_sort - sorts an array of int in ascending order
 * @array: array that is being sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int beg = 0, pivot;

	if (array && size > 1)
	{
		pivot = (size - 1);
		divide(beg, pivot, array, size);
	}
}
/**
* divide - recursively partition between array
* @beg: start of the divided array
* @pivot: end of the divided array
* @i: start of the array
* @size: size of the array
**/
void divide(int beg, int pivot, int *i, size_t size)
{
	int first, second, np;

	if (beg < pivot)
	{
		second = partition(beg, pivot, i, size);
		first = beg;
		np = second - 1;
		if (first != np && second != pivot)
			np--;
		divide(first, np, i, size);
		divide(second, pivot, i, size);
	}
}
/**
* partition - divides an array
* @beg: start of array separated
* @pivot: end of array separated
* @i: the start of array
* @size: size of array
* Return: new start
**/
int partition(int beg, int pivot, int *i, size_t size)
{
	int temp;

	temp = beg;
	while (temp != pivot)
	{
		if (i[temp] < i[pivot])
		{
			if (temp != beg)
			{
				swap_int(i + temp, i + beg);
				print_array(i, size);
			}
			temp++;
			beg++;
		}
		else
			temp++;
	}
	if (beg != pivot)
	{
		if (i[beg] > i[pivot])
		{
			swap_int(i + pivot, i + beg);
			print_array(i, size);
		}
		beg++;
	}
	return (beg);
}

/**
  * swap_int - swaps the values of two integers
  * @a: take an integer
  * @b: take an integer
  */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

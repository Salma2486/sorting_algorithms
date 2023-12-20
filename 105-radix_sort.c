#include "sort.h"
/**
 *getMax - This is the entry point of the code
 *@size: tew5t r
 *@array: trhs
 *Return:0 Success
 */
int getMax(const int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort -  str hgsrt hrts h
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: tedy ujt5edy uj
 * @ptr: Ttu jirfy ik
 */
void radix_counting_sort(int *array, size_t size, int exp, int *ptr)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		ptr[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = ptr[i];
}

/**
 * radix_sort - Sorts an array of
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *ptr;

	if (array == NULL || size < 2)
		return;

	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
		return;

	max = getMax(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_counting_sort(array, size, exp, ptr);
		print_array(array, size);
	}

	free(ptr);
}

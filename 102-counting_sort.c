#include "sort.h"
/**
 * counting_sort - sort ....
 * @array: an array
 * @size: the size of array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = array[0], j;
	size_t i;
	int *count_array;
	int *sorted_arr;

	if (array == NULL || size <= 1)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	count_array = calloc(max_value + 1, sizeof(int));

	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j <= max_value; j++)
	{
		count_array[j] += count_array[j - 1];
	}
	print_array(count_array, max_value + 1);
	sorted_arr = malloc(size * sizeof(int));

	for (j = size - 1; j >= 0; j--)
	{
		sorted_arr[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];

	free(count_array);
	free(sorted_arr);
}

#include <stdio.h>
#include <stdlib.h>
/**
 * counting_sort - sort ....
 * @array: an array
 * @size: the size of array
 */
void counting_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	int max_value = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	int *count_array = calloc(max_value + 1, sizeof(int));

	for (size_t i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}

	for (int i = 1; i <= max_value; i++)
	{
		count_array[i] += count_array[i - 1];
	}
	int *sorted_arr = malloc(size * sizeof(int));

	for (int i = size - 1; i >= 0; i--)
	{
		sorted_arr[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (size_t i = 0; i < size; i++)
		array[i] = sorted_arr[i];

	free(count_array);
	free(sorted_arr);
}

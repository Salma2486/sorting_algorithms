#include "sort.h"
/**
 *selection_sort - This is the entry point of the code
 *@array: ers g
 *@size: setg
 *Return:0 Success
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)

			if (array[j] < array[min])
			{
				min = j;
			}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
		print_array(array, size);
	}

}

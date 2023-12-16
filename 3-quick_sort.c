#include "sort.h"
void swap(int *x, int *y);
void rec(int *array, int low, int high);
int partition(int *array, int low, int high);
void quick_sort(int *array, size_t size);
/**
 *swap - This is the entry point of the code
 *@x: trea gt
 *@y: qetgrf
 *Return:0 Success
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 *lomuto_partition - This is the entry point of the code
 *@array: 43we f
 *@low: grae
 *@high: gtear
 *@size: ysreh
 *Return:0 Success
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}

	swap(&array[i], &array[high]);
	print_array(array, size);

	return (i);
}
/**
 *quick_sort_recursive - This is the entry point of the code
 *@array: egd
 *@low: stegrr
 *@high: etagr
 *@size: tragfe
 *Return:0 Success
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}
/**
 *quick_sort - This is the entry point of the code
 *@array: esy5w
 *@size: rydsht
 *Return:0 Success
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

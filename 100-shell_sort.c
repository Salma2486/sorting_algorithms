#include "sort.h"
/**
 * shell_sort - using the Knuth sequence
 *@array: the array to be sorted
 *@size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1;
	while (interval <= size / 3) {
		interval = interval * 3 + 1;
	}

	while (interval > 0) {
		for (int i = interval; i < size; i++) {
			int temp = array[i];
			int j = i;

			while (j >= interval && array[j - interval] > temp) {
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}

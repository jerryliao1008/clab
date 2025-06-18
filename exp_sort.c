#include <stdio.h>
#include <stdint.h>

/*
 * Demonstrates both insertion sort and bubble sort on a uint8_t array.
 */

void insertion_sort(uint8_t arr[], int len)
{
	uint8_t i, j, temp;

	for (i = 1; i < len; i++) {
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

void bubble_sort(uint8_t arr[], int len)
{
	int i, j;
	uint8_t temp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void print_array(const char *label, uint8_t arr[], int len)
{
	int i;
	printf("%s", label);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	uint8_t data1[5] = { 5, 12, 1, 34, 20 };
	uint8_t data2[5] = { 5, 12, 1, 34, 20 };
	int len = sizeof(data1) / sizeof(data1[0]);

	printf("Original array: ");
	print_array("", data1, len);

	insertion_sort(data1, len);
	print_array("After insertion sort: ", data1, len);

	bubble_sort(data2, len);
	print_array("After bubble sort:    ", data2, len);

	return 0;
}


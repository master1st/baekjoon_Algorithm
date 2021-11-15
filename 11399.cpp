#include <stdio.h>
#include <stdlib.h>
void swap(int* arr1, int* arr2) {
	int tmp;
	tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = tmp;
}

int main(void) {
	int peoples;
	scanf("%d", &peoples);
	int timesum = 0;
	int* peopletime = (int*)malloc(sizeof(int)*peoples);

	for (int i = 0; i < peoples; i++) {
		scanf("%d", &peopletime[i]);
	}
	for (int i = 0; i < peoples; i++) {
		for (int j = 0; j < peoples - 1; j++) {
			if (peopletime[j] > peopletime[j + 1]) {
				swap(&peopletime[j], &peopletime[j + 1]);
			}
		}
	}
	for (int i = 0; i < peoples; i++) {
		for (int j = 0; j <= i; j++) {
			timesum += peopletime[j];
		}
	}
	printf("%d", timesum);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int blue = 0; int white = 0;
void BinarySearch(int** arr, int x, int y, int e)
{
	int count = 0;
	

	for (int i = x; i < x + e; i++) {
		for (int j = y; j < y + e; j++) {
			if (arr[i][j] == 1)
				count++;
		}
	} 
	if (count == 0) white++;
	else if (count == e * e) {
		blue++;
	}
	
	else {
		BinarySearch(arr, x, y, e / 2);
		BinarySearch(arr, x, y + e / 2, e / 2);
		BinarySearch(arr, x + e / 2, y, e / 2);
		BinarySearch(arr, x + e / 2, y + e / 2, e / 2);
	}
	return;
}


int main(void) {

	int i = 0; 
	printf("%d", !i);
	int n = 0;
	int** arr;
	scanf("%d", &n);
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	BinarySearch(arr, 0, 0, n);
	printf("%d\n", white);
	printf("%d\n", blue);
	
	return 0;

}

// n/2 개를 계속 자르고 재귀호출 식으로 만든다. 근데 이거 배열이잖아..
// 3. 그 2차원배열을 계속 반으로 쪼갠다. 단순히 값을 계속 분할 한다음
// 4. 정복해서 만약 2차원 배열 값이 전부 1이나 0이 될때까지해서 만약 맞으면
// 변수 2개를 등록해놓고 그 변수 숫자를 하나씩 증가시켜서 나중에 출력시켜주도록.
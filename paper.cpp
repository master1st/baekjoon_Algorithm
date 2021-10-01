
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

// n/2 ���� ��� �ڸ��� ���ȣ�� ������ �����. �ٵ� �̰� �迭���ݾ�..
// 3. �� 2�����迭�� ��� ������ �ɰ���. �ܼ��� ���� ��� ���� �Ѵ���
// 4. �����ؼ� ���� 2���� �迭 ���� ���� 1�̳� 0�� �ɶ������ؼ� ���� ������
// ���� 2���� ����س��� �� ���� ���ڸ� �ϳ��� �������Ѽ� ���߿� ��½����ֵ���.
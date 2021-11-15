#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int n , k;
	
	scanf("%d %d", &n, &k);
	
	int* money = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &money[i]);
	}
	int count = 0;
	int j = n - 1;
	while(k > 0){
		if (k >= money[j]) {
			k -= money[j];
			count++;
		}
		else {
			j--;
		}
	}
	printf("%d", count);
	return 0;
}// 1 2 3 4 5 6 7 8 9 10 
// 9 8 7 6 5 4 3 2 1 
#include <stdio.h>

int fibonacch(int n)
{
	int i, j;
	i = 1;
	j = 0;
	for (int k = 0; k < n; k++) {
		j = i;
		i = k + 1;
	}
	return j;
}
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d", fibonacch(n));
	
}


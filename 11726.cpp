#include <stdio.h>

int main(void) {
	int m;
	scanf("%d", &m);
	int dp[1001];

	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= m; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	printf("%d", dp[m]);
}
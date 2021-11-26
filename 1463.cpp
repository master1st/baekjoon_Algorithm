#include <stdio.h>
#define Min(x,y) (x > y ? y : x)
int dp[1000001];
int main(void)
{
	int req;
	int m = 0, n = 0;
	scanf("%d", &req);
	for (int i = 2; i <= req; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = Min(dp[i],dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = Min(dp[i],dp[i / 3] + 1);
	}
	
	printf("%d", dp[req]);
	return 0;
}



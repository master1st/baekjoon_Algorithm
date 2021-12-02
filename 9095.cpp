#include <stdio.h>

int main() {
    int dp[11] = { 0 };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int j, n;
    scanf("%d", &j);
    
    for (int i = 0; i < j; i++) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }

    return 0;
}
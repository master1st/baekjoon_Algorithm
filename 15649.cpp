#include <stdio.h>
int n, m;
bool visit[9];
int check[9];

void dfs(int root) 
{
	if (root == m + 1)
	{
		for (int i = 1; i <= m; i++)
		{
			printf("%d ", check[i]);
		}
		printf("\n");
	}
	else
	{ 
		for (int i = 1; i <= n; i++) 
		{
			if (visit[i] == false) 
			{
				visit[i] = true;
				check[root] = i;
				dfs(i + 1);
				visit[i] = false;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	dfs(1);
} 

// 1 2 3 4 1 2 4 3 
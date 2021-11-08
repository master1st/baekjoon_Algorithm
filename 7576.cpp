#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int dx[] = { -1,0,1,0};
int dy[] = { 0,1,0,-1 };
int visited[1001][1001];
int graph[1001][1001];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	queue<pair<int, int>>q;
	for (unsigned short i = 0; i < m; ++i)
	{
		for (unsigned short j = 0; j < n; ++j)
		{
			scanf("%d", &graph[i][j]);

			if (graph[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visited[i][j] = graph[i][j];
			}
			if (graph[i][j] == -1)
			{
				visited[i][j] = graph[i][j];
			}
		}
	}
	while (!q.empty())
	{
		int x, y;
		x = q.front().first, y = q.front().second;
		q.pop();
		for (unsigned int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i], yn = y + dy[i];

			//밖으로 나가는 경우없이, 안익은 토마토만을 찾고 실제로 visited에도
			//안익은 토마토로 검증되어있는 토마토들만
			if (xn >= 0 && xn < m && yn >= 0 && yn < n &&
				graph[xn][yn] == 0 && graph[xn][yn] != -1 && visited[xn][yn] == 0)
			{
				q.push(make_pair(xn, yn));
				visited[xn][yn] = visited[x][y] + 1;
				//단순 while문을 이용해서 q에 사분위를 넣어준다음 검색한다.
			}
		}
	} 
	int tdays = 0;
	for (unsigned short i = 0; i < m; ++i)
	{
		for (int unsigned short j = 0; j < n; ++j)
		{
			if (tdays < visited[i][j])
				tdays = visited[i][j];
		}
	}

	for (unsigned short i = 0; i <m ; ++i) 
	{
		for (unsigned short j = 0; j <n ; ++j) 
		{
			if (visited[i][j] == 0) 
			{
				tdays = 0;
			}
		}
	}
	
	printf("%d\n", tdays - 1);
	return 0;
}
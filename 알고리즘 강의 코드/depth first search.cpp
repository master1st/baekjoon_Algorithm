#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
bool visit[10001];
vector<int> edge[10001];

bool initVisit()
{
	for (int i = 0; i < 10001; i++)
		visit[i] = false;
}
void dfs(int v)
{
	if (visit[v] == true) {
		return;
	}
	printf("%d ", v);
	visit[v] = true;
	for (int i = 0; i < edge[v].size(); i++) {
		dfs(edge[v][i]);
	}

}
void main()
{
	int u, v;
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		edge[u].push_back(v);
		edge[v].push_back(u);
		//인접리스트 생성. 
	}

	for (int i = 1; i <= n; i++)
		sort(edge[i].begin(), edge[i].end());

	initVisit();
	for (int i = 1; i < n; i++) {
		if (visit[i] == false)
			dfs(i);
	}
	//sort가 필요한 이유는 위에 벡터를 인접리스트 형식으로 만들어줬으면,
	// 무작위로 연결된 것들을 집어넣을텐데 1,2,3,4번 인덱스의 벡터들에 있어서
	// 인접한 값들이 순서대로 정렬되도록. 

}
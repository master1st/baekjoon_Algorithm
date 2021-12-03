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
		//��������Ʈ ����. 
	}

	for (int i = 1; i <= n; i++)
		sort(edge[i].begin(), edge[i].end());

	initVisit();
	for (int i = 1; i < n; i++) {
		if (visit[i] == false)
			dfs(i);
	}
	//sort�� �ʿ��� ������ ���� ���͸� ��������Ʈ �������� �����������,
	// �������� ����� �͵��� ��������ٵ� 1,2,3,4�� �ε����� ���͵鿡 �־
	// ������ ������ ������� ���ĵǵ���. 

}
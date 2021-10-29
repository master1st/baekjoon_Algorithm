#include <algorithm>
#include <vector>
using namespace std;
bool visit[101];
vector<int> graph[101];

void initVisit()
{
	for (int i = 0; i < 101; i++)
		visit[i] = false;
}

void dfs(int v)
{
	static int count = 0;

	if (visit[1])
		count++;
	visit[v] = true;
	
	
	for (int i = 0; i < graph[v].size(); i++) {
		if (visit[graph[v][i]] == false) {
			dfs(graph[v][i]);
		}
	}
	printf("%d", count);
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	initVisit();
	if (visit[1] == false)
		dfs(1);
	
}
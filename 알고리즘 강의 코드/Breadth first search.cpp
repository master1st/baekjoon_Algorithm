#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000001
using namespace std;

vector<int> edge[10001];
int dist[10001];

void initDist() {
	for (int i = 0; i < 10001; i++) {
		dist[i] = INF;
	}
}

int bfs(int s) {
	queue<int> q;
	int now, k, next;

	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		now = q.front();	//큐에서 가져오고
		q.pop();	//제거
		printf("%d ", now);
		for (int k = 0; k < edge[now].size(); k++) {
			next = edge[now][k];
			if (dist[next] == INF) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}

	}
}
int main(void) {
	int n;
	initDist();
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) {
			bfs(i);
		}
	}
}
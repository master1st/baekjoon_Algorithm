
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

using namespace std;
#define max_m 10004
bool group[max_m];
vector<pair<int, int>> graph[max_m];

void check(void) {
	for (int i = 0; i < max_m; i++) {
		group[i] = false;
	}
}

int main(void) {
	int vn, en;
	int u, v, w;
	int sum = 0;
	scanf("%d %d", &vn, &en);
	for (int i = 0; i < vn; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	int start = 1;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int ver = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if (group[ver]) continue;
		group[ver] = true;

		for (int i = 0; i < graph[ver].size(); i++) {
			pair<int, int>nx = graph[ver][i];
			if (group[nx.first] == false)
				pq.push(make_pair(nx.second, nx.first));
		}
		sum += dist;
	}
	printf("%d", sum);
}



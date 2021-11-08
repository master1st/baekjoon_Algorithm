#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[1001];
int dist[1001];

#define max_n 1001
#define max_m 100001
#define INF 1000000
vector<pair<int,int>>graph[max_m];
int n, m;
void dijkstra(int start)
{
    int i;
    int u, v;
    int distu, distv;

    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, -1);
    dist[start] = 0;
    prev[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({ 0, start });
    

    while (!pq.empty()) {
        u = pq.top().second;
        distu = pq.top().first;
        pq.pop();
        
        for (i = 0; i < graph[u].size(); i++) {
            v = graph[u][i].first;
            distv = distu + graph[u][i].second;
            if (dist[v] > distv) {
                dist[v] = distv;
                prev[v] = u;
                pq.push({ distv, v });
            }
        }
       }

    for (int i = 1; i <= n; i++)
        printf("%d\n", dist[i]);
    printf("\n");
}
int main(void)
{

    scanf("%d %d", &n, &m);
    int start;
    scanf("%d", &start);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair( v,w ));
    }

    dijkstra(start);

}


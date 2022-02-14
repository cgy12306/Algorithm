// https://www.acmicpc.net/problem/1504
// 특정한 최단 경로
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N, E, INF = 999999999;
int minCost[802];
vector<vector<pair<int, int>>> Edge;

void dijkstra(int start) {
	fill(minCost, minCost + N + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	minCost[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (minCost[current] < cost) continue;

		for (auto e : Edge[current]) {
			int nextCost = e.first + cost;
			int next = e.second;
			if (minCost[next] > nextCost) {
				minCost[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> E;
	Edge.resize(N + 1);

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Edge[from].push_back(make_pair(cost, to));
		Edge[to].push_back(make_pair(cost, from));
	}
	int v1, v2, ans1 = 0, ans2 = 0, ans = 0;
	cin >> v1 >> v2;
	bool flag = false;
	
	dijkstra(1);
	ans1 += minCost[v1];
	dijkstra(v1);
	ans1 += minCost[v2];
	dijkstra(v2);
	ans1 += minCost[N];

	dijkstra(1);
	ans2 += minCost[v2];
	dijkstra(v2);
	ans2 += minCost[v1];
	dijkstra(v1);
	ans2 += minCost[N];
	
	ans = min(ans1, ans2);
	ans = min(INF, ans);
	if (ans >= INF || ans <= 0) cout << "-1";
	else cout << ans;
}
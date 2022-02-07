// https://www.acmicpc.net/problem/10217
// KCM Travel
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;
int N, M, K, INF = 999999999;
vector<vector<tuple<int, int, int>>> Edges;
int minCost[102][10002];

void dijkstra(int start) {
	priority_queue<tuple<int, int, int>> pq;
	minCost[start][0] = 0;
	pq.push({ 0, 0, start });
	
	while (!pq.empty()) {
		int current = get<2>(pq.top());
		int cost = get<1>(pq.top());
		int time = -get<0>(pq.top());
		pq.pop();
		if (minCost[current][cost] < time) continue;

		for (auto e : Edges[current]) {
			int next = get<2>(e);
			int nextCost = get<1>(e) + cost;
			int nextTime = get<0>(e) + time;

			if (nextCost > M) continue;
			if (minCost[next][nextCost] > nextTime ) {
				minCost[next][nextCost] = nextTime;
				pq.push({ -nextTime, nextCost, next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		Edges.resize(N + 1);
		fill(minCost[0], minCost[102], INF);

		for (int i = 0; i < K; i++) {
			int from, to, cost, time;
			cin >> from >> to >> cost >> time;
			Edges[from].push_back({ time, cost, to });
		}
		dijkstra(1);
		int ans = INF;
		for (int i = 0; i <= M; i++) {
			ans = min(ans, minCost[N][i]);
		}
		ans == INF ? cout << "Poor KCM\n" : cout << ans << "\n";
		Edges.clear();
	}
}
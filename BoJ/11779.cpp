// https://www.acmicpc.net/problem/11779
// 최소비용 구하기 2
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int N, M, minCost[1002], INF = 999999999, path[1002];
vector<int> ans;
vector<vector<pair<int, int>>> Edges;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	minCost[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();
		if (minCost[current] < cost) continue;

		for (auto e : Edges[current]) {
			int next = e.second;
			int nextCost = e.first + cost;
		
			if (minCost[next] > nextCost) {
				minCost[next] = nextCost;
				path[next] = current;
				pq.push({ -nextCost, next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	Edges.resize(N + 1);

	fill(minCost, minCost + N + 1, INF);

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Edges[from].push_back({ cost, to });
	}

	int from, to;
	cin >> from >> to;

	dijkstra(from);


	cout << minCost[to] << "\n";
	

	while (to) {
		ans.push_back(to);
		to = path[to];
	}
	cout << ans.size() << "\n";
	
	for (int i = ans.size() - 1; i >= 0; i--)cout << ans[i] << " ";
	
}
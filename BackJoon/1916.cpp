// https://www.acmicpc.net/problem/1753
// 최단경로
#include<iostream>
#include<queue>
#include<vector>
#include<queue>
using namespace std;
int V, E, start, INF = 999999999;
int minCost[20001];
vector <vector<pair<int, int>>> Edge;
void dijkstra(int start) {

	priority_queue<pair<int, int>> pq;
	minCost[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;
		
		pq.pop();

		if (minCost[current] < cost) continue;

		for (int i = 0; i < Edge[current].size(); i++) {
			int next = Edge[current][i].second;
			int nextCost = Edge[current][i].first + cost;
			if (minCost[next] > nextCost) {
				minCost[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> start;

	Edge.resize(V + 1);
	fill(minCost, minCost + V + 1, INF);

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Edge[from].push_back(make_pair(cost, to));
	}

	dijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (minCost[i] == INF) cout << "INF\n";
		else cout << minCost[i] << "\n";
	}
}
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
int V, E, S, INF = 999999999;

vector<vector<pair<int,int>>> Edges;
int minCost[20002];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	minCost[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;

		pq.pop();

		if (minCost[current] < cost) continue;

		/*for (int i = 0; i < Edges[current].size(); i++) {
			int next = Edges[current][i].second;
			int nextCost = Edges[current][i].first + cost;

			if (minCost[next] > nextCost) {
				minCost[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
		*/
		for (auto e : Edges[current]) {
			int next = e.second;
			int nextCost = e.first + cost;
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
	cin >> V >> E >> S;
	Edges.resize(V + 1);
	fill(minCost, minCost + V + 1, INF);

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Edges[from].push_back(make_pair(cost, to));
	}

	dijkstra(S);
	for (int i = 1; i <= V; i++) {
		if (minCost[i] == INF) cout << "INF\n";
		else cout << minCost[i] << "\n";
	}
}
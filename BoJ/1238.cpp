// https://www.acmicpc.net/problem/1238
// ÆÄÆ¼
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int N, M, X, Max = 0, INF = 999999999, ans = 0;
int minCost[1002];
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
int goback() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
		sum = minCost[X];
		dijkstra(X);
		sum += minCost[i];
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	Edge.resize(N + 1);

	for (int i = 1; i <= M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Edge[from].push_back(make_pair(cost, to));
	}

	cout << goback();
}
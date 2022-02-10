// https://www.acmicpc.net/problem/11657
// 타임머신
#include<iostream>
#include<vector>
#include<cstring>
#include<tuple>

using namespace std;
int N, M;
vector<vector<pair<int, int>>> Edge;
long long minCost[502];
int INF = 999999999;

bool bellman_ford(int start) {
	fill(minCost, minCost + N + 1, INF);
	
	minCost[start] = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N ; j++) {
			int current = j;
			for (auto e : Edge[j]) {
				int next = e.second;
				int cost = e.first;
				long long nextCost = minCost[current] + cost;
				if (minCost[current] != INF && minCost[next] > nextCost) {
					minCost[next] = nextCost;
					if (i == N - 1) return true;
				}
			}
		}
	}
	
	return false;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	Edge.resize(N + 1);
	
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Edge[from].push_back(make_pair(cost, to));
	}
	

	if (bellman_ford(1)) {
		cout << "-1";
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (minCost[i] == INF) cout << "-1\n";
			else cout << minCost[i] << "\n";
		}
	}

}
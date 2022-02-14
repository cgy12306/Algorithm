// https://www.acmicpc.net/problem/2606
// 바이러스
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &edge, vector<bool> &infested, int start) {

	infested[start] = true;

	for (auto next : edge[start]) {
		if (!infested[next]) {
			dfs(edge, infested, next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E, from, to, cnt = 0;
	cin >> V >> E;
	vector<vector<int>> edge(V + 1);
	vector<bool> infested(V + 1, false);

	for (int i = 0; i < E; i++) {
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	dfs(edge, infested, 1);
	
	for (int v = 1; v <= V; v++) {
		if (infested[v]) cnt++;
	}
	cout << cnt - 1;
}
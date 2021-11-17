// https://www.acmicpc.net/problem/11725
// 트리의 부모 찾기

#include<iostream>
#include<vector>
using namespace std;

int N;

void dfs(vector<vector<int>> &edge, vector<bool> &visited, vector<int> &parent, int start) {
	visited[start] = true;

	for (auto next : edge[start]) {
		if (!visited[next]) {
			parent[next] = start;
			dfs(edge, visited, parent, next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	vector<vector<int>> edge(N+1);
	vector<bool> visited(N+1, false);
	vector<int> parent(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	for (int node = 1; node <= N; node++) {
		if (!visited[node]) {
			dfs(edge, visited, parent, node);
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}
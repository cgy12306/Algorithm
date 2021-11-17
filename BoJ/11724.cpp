// https://www.acmicpc.net/problem/11724
// 연결 요소의 개수

#include<iostream>
#include<vector>
using namespace std;

int N, M, u, v;

void dfs(vector<vector<int>> &e, int start, vector<bool> &visit) {
	visit[start] = true;

	for (auto next : e[start]) {
		if (!visit[next]) {
			dfs(e, next, visit);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// N : 정점의 개수, M : 간선의 개수

	cin >> N >> M;

	vector<vector <int>> e(N + 1);
	vector<bool> visit(N + 1, false);


	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(e, i, visit);
			cnt++;
		}
	}
	cout << cnt;

}
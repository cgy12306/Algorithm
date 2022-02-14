// https://www.acmicpc.net/problem/1167
// 트리의 지름

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001];
int sum = 0, sp;
void dfs(int start, int length) {
	visited[start] = true;

	if (sum < length) {
		sum = length;
		sp = start;
	}

	for (auto next : tree[start]) {
		if (!visited[next.first]) {
			dfs(next.first, length + next.second);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V;

	cin >> V;

	for (int i = 0; i < V; i++) {
		int from, to, length;

		cin >> from;

		while (1) {
			cin >> to;

			if (to == -1) break;

			cin >> length;
			tree[from].push_back(make_pair(to, length));
			tree[to].push_back(make_pair(from, length));
		}
	}
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(sp, 0);

	cout << sum;

}
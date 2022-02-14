// https://www.acmicpc.net/problem/1967
// 트리의 지름

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
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
	
	int N;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int from, to, length;

		cin >> from >> to >> length;
		tree[from].push_back(make_pair(to, length));
		tree[to].push_back(make_pair(from, length));
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(sp, 0);

	cout << sum;

}
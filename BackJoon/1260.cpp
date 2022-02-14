/*
[1260] DFS와 BFS
https://www.acmicpc.net/problem/1260

*/
#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int arr[1001][1001] = { 0, };
int visit[1001];
int n, m;
queue<int> q;

void dfs(int v) {
	cout << v << " ";
	visit[v] = 1;

	for (int i = 1; i <= n; i++) {
		if (arr[v][i] == 1 && visit[i] == 0) {
			dfs(i);
		}
	}
	return;
}

void bfs(int v) {
	q.push(v);
	visit[v] = 1;
	while (!q.empty())
	{
		v = q.front();
		visit[v] = 1;
		cout << v << " ";
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[v][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, x, y;
	// n : 정점의 개수, m : 간선의 개수, v : 시작할 정점의 번호
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	dfs(v);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	bfs(v);

}
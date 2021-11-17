// https://www.acmicpc.net/problem/7576
// ≈‰∏∂≈‰
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[1001][1001];
bool visited[1001][1001];
int day[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int M, N, res = 0;

void bfs() {
	queue<pair<int, int>> que;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				que.push(make_pair(i, j));
			}
		}
	}

	while (!que.empty()) {
		int x = que.front().second;
		int y = que.front().first;

		visited[y][x] = true;
		map[y][x] = 1;

		que.pop();

		for (int i = 0; i < 4; i++) {	
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax < 0 || ay < 0 || ax >= M || ay >= N) continue;

			if (map[ay][ax] != 0 || visited[ay][ax]) continue;

			visited[ay][ax] = true;
			map[ay][ax] = 1;
			day[ay][ax] = day[y][x] + 1;
			que.push(make_pair(ay, ax));
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << day[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			res = max(day[i][j], res);
		}
	}
	cout << res;
}
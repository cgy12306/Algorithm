// https://www.acmicpc.net/problem/2589
// º¸¹°¼¶

#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
int N, M;
char map[51][51];
int visited[51][51];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(int x, int y) {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] =='W') continue;

			if (visited[nx][ny] == 0 ) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	int Max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Max = max(Max, visited[i][j]);
		}
	}
	return Max - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				ans = max(bfs(i, j), ans);
			}
		}
	}
	cout << ans;
}
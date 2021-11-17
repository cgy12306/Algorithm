// https://www.acmicpc.net/problem/2178
// ¹Ì·Î Å½»ö

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, map[102][102], movement[102][102];
bool visited[102][102];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs() {
	queue < pair<int, int>> que;
	que.push(make_pair(1, 1));

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++){
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax <= 0 || ay <= 0 || ax > M || ay > N) continue;

			if (map[ay][ax] != 1 || visited[ay][ax]) continue;
			visited[ay][ax] = true;
			movement[ay][ax] = movement[y][x]+1;
			que.push(make_pair(ax, ay));
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num;
			num = cin.get();
			if (num == '\n') {
				num = cin.get();
			}
			map[i][j] = num - 48;
		}
	}

	bfs();

	cout << movement[N][M] + 1;
}
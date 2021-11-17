// https://www.acmicpc.net/problem/7569
// 토마토
#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

int M, N, H, map[101][101][101], day[101][101][101], res = 0;
bool visited[101][101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int dz[] = { 1, -1 };

void bfs() {
	queue<tuple<int, int, int>> que;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[h][i][j] == 1) {
					que.push(make_tuple(h, i, j)); // 높이 세로 가로
				}
			}
		}
	}
	while (!que.empty()) {
		int z = get<0>(que.front());
		int y = get<1>(que.front());
		int x = get<2>(que.front());

		que.pop();

		for (int i = 0; i < 4; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax < 0 || ay < 0 || ax >= M || ay >= N) continue;

			if (map[z][ay][ax] != 0 || visited[z][ay][ax]) continue;

			visited[z][ay][ax] = true;
			map[z][ay][ax] = 1;
			day[z][ay][ax] = day[z][y][x] + 1;
			que.push(make_tuple(z, ay, ax));
		}
		for (int i = 0; i < 2; i++) {
			int az = z + dz[i];
			if (az < 0 || az >= H) continue;
			
			if (map[az][y][x] != 0 || visited[az][y][x]) continue;

			visited[az][y][x] = true;
			map[az][y][x] = 1;
			day[az][y][x] = day[z][y][x] + 1;
			que.push(make_tuple(az, y, x));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[h][i][j];
			}
		}
	}

	bfs();
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[h][i][j] == 0) {
					cout << "-1";
					return 0;
				}
				res = max(day[h][i][j], res);
			}
		}
	}
	cout << res;
}
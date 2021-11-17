// https://www.acmicpc.net/problem/4963
// ¼¶ÀÇ °³¼ö

#include<iostream>
#include<queue>
#include<cstring>

int map[51][51], X, Y, cnt = 0;
bool visited[51][51];
using namespace std;

int dx[] = { 0,0,-1,1,1,1,-1,-1 };
int dy[] = { -1,1,0,0,1,-1,1,-1 };

void bfs(int x, int y) {
	visited[y][x] = true;
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));

	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();

		for (int i = 0; i < 8; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax < 0 || ay < 0 || ax >= X || ay >= Y) continue;

			if (map[ay][ax] != 1 || visited[ay][ax]) continue;

			visited[ay][ax] = true;
			que.push(make_pair(ax, ay));
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	while (true) {
		cin >> X >> Y;
		if (X == 0 && Y == 0) break;
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					bfs(j, i);
					cnt++;
				}
			}
		}
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		cout << cnt << "\n";
		cnt = 0;
	}

}
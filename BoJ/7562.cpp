// https://www.acmicpc.net/problem/7562
// 나이트의 이동

#include<iostream>
#include<queue>
#include<cstring>

int T, N, map[301][301], from_x, from_y, to_x, to_y;
int visited[301][301];
using namespace std;

int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
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

			if (ax < 0 || ay < 0 || ax >= N || ay >= N) continue;
			if (visited[ay][ax]) continue;

			visited[ay][ax] = visited[y][x] + 1;
			
			que.push(make_pair(ax, ay));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++){
		cin >> N;
		cin >> from_x >> from_y >> to_x >> to_y;

		bfs(from_x, from_y);

		cout << visited[to_y][to_x] - 1 <<"\n";
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

	}
}
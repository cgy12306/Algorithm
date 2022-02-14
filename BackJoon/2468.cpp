// https://www.acmicpc.net/problem/2468
// 안전 영역

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int map[102][102], N, cnt = 0, max_height = 0;
bool visited[102][102];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector<int> height;

void bfs(int x, int y, int h) {
	queue<pair<int,int>> que;
	visited[y][x] = true;
	que.push(make_pair(x, y));

	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax <= 0 || ay <= 0 || ax > N || ay > N) continue;

			if (map[ay][ax] <= h || visited[ay][ax]) continue;
			visited[ay][ax] = true;
			que.push(make_pair(ax, ay));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			max_height = max(max_height, map[i][j]);
		}
	}
	for (int h = 1; h < max_height; h++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] > h && !visited[i][j]) {
					bfs(j, i, h);
					cnt++;
				}
			}
		}
		memset(visited, false, sizeof(visited));
		height.push_back(cnt);
		cnt = 0;
	}
	height.push_back(1);
	sort(height.begin(), height.end(), greater<>());
	cout << height[0];
}
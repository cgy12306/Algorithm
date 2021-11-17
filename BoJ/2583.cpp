// https://www.acmicpc.net/problem/2583
// 영역 구하기
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

int Y, X, K, map[101][101], cnt = 0;
bool visited[101][101];

using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<int> area;

void bfs(int x, int y) {
	visited[y][x] = true;
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));
	int acnt = 0;

	while (!que.empty()){
		
		x = que.front().first;
		y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax < 0 || ay < 0 || ax >= X || ay >= Y) continue;

			if (map[ay][ax] == 1 || visited[ay][ax]) continue;

			visited[ay][ax] = true;
			que.push(make_pair(ax, ay));
		}
		acnt++;
	}
	area.push_back(acnt);
	acnt = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> X >> K;

	for (int k = 0; k < K; k++) {
		int from_x, from_y, to_x, to_y;
		cin >> from_x >> from_y >> to_x >> to_y;
		for (int i = from_y; i < to_y; i++) {
			for (int j = from_x; j < to_x; j++) {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				bfs(j, i);
				cnt++;
			}
		}
	}
	sort(area.begin(), area.end());
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << area[i] << " ";
	}

}
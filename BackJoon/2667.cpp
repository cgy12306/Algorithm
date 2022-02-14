// https://www.acmicpc.net/problem/2667
// 단지번호붙이기

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int map[27][27], N, cnt = 0, tcnt = 0;
bool visited[27][27];
vector<int> town;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void bfs(int x, int y) {
	queue<pair<int, int>> que;

	que.push(make_pair(x, y));

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		map[y][x] = 0;
		que.pop();

		tcnt++;

		for (int i = 0; i < 4; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax <= 0 || ay <= 0 || ax > N || ay > N)continue;

			if (map[ay][ax] != 1 || visited[ay][ax]) continue;
			map[ay][ax] = 0;
			visited[ay][ax] = true;
			que.push(make_pair(ax, ay));
		}
	}
	town.push_back(tcnt);
	tcnt = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			num = cin.get();
			if (num == '\n') {
				num = cin.get();
			}
			map[i][j] = num - 48;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				bfs(j, i);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";

	sort(town.begin(), town.end());

	for (int i = 0; i < cnt; i++) {
		cout << town[i] << "\n";
	}
}
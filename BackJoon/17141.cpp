// https://www.acmicpc.net/problem/17141
// ¿¬±¸¼Ò 2
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int N, map[51][51], tmap[51][51], M, res = 99999999, Max = 0;
bool visited[51][51], vmap[51][51];
int dx[] = {-1, 1 ,0 ,0};
int dy[] = {0, 0, -1, 1};


queue<pair<int, int>> que;
vector<pair<int, int>> virus;
vector<int> check;

void bfs(int x, int y) {
	
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		
		vmap[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (tmap[nx][ny] != 0 || vmap[nx][ny]) continue;

			tmap[nx][ny] = tmap[x][y] + 1;

			que.push(make_pair(nx, ny));
		}		
	}

}
void brute_force() {
	
	do {
		
		memcpy(tmap, map, sizeof(map));
		memcpy(vmap, visited, sizeof(visited));
		
		for (int i = 0; i < check.size(); i++) {
			if (check[i]) {
				tmap[virus[i].first][virus[i].second] = 1;
				vmap[virus[i].first][virus[i].second] = true;
			}
			else {
				tmap[virus[i].first][virus[i].second] = 0;
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tmap[i][j] == 1 && vmap[i][j]) {
					que.push(make_pair(i, j));
				}
			}
		}

		bfs(que.front().first, que.front().second);
		
		Max = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Max = max(Max, tmap[i][j]);
				if (tmap[i][j] == 0) flag = true;
			}
		}

		Max -= 1;

		if (flag) continue;

		res = min(Max, res);

	} while (next_permutation(check.begin(), check.end()));

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
				check.push_back(0);
			}
		}
	}
	for (int i = 0; i < M; i++) check[i] = 1;
	sort(check.begin(), check.end());
	
	brute_force();
	
	if (res == 99999999) {
		cout << -1;
	}
	else {
		cout << res;
	}
}
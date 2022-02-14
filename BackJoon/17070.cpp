// https://www.acmicpc.net/problem/17070
// 파이프 옮기기1
#include<iostream>

using namespace std;
int N, cnt;
int map[17][17];
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 1, 0 };
// 가로 1, 대각 2, 가로 3
bool check(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx >= N || ny >= N || map[nx][ny] == 1) return false;

	if (dir == 0) {
		if (map[x][y+1] == 1) return false;
	}
	else if (dir == 1) {
		for (int i = 0; i < 3; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (map[nx][ny] == 1) return false;
		}
	}
	else {
		if (map[x + 1][y] == 1)return false;
	}
	
	return true;
}
void dfs(int x, int y, int dir) {
	if (x == N - 1 && y == N - 1) {
		cnt++;
		return;
	}

	if (dir == 0) {
		for (int i = 0; i < 2; i++) {
			if (!check(x, y, i)) continue;
			dfs(x + dx[i], y + dy[i], i);
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < 3; i++) {
			if (!check(x, y, i)) continue;
			
			dfs(x + dx[i], y + dy[i], i);
		}
	}
	else if (dir == 2) {
		for (int i = 1; i < 3; i++) {
			if (!check(x, y, i)) continue;
			dfs(x + dx[i], y + dy[i], i);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 1, 0);

	cout << cnt;
}
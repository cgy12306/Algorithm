#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int R, C, ans = 0;

char map[22][22];
bool visited[27];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0 , 0, 1, -1 };

void dfs(int x, int y, int cnt) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

		if (!visited[map[nx][ny] - 'A']) {
			visited[map[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			visited[map[nx][ny] - 'A'] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {			
			cin >> map[i][j];
		}
	}
	visited[map[0][0]-'A'] = true;
	dfs(0, 0, 1);

	cout << ans;

}
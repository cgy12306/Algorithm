#include<iostream>

using namespace std;

int N;
char map[101][101];
int visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt) {
	visited[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[x][y] != map[nx][ny]) continue;

		if (visited[nx][ny] == 0) {
			dfs(nx, ny, cnt);
		}
	}
}
void run() {

	int cnt = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}

	cout << cnt - 1 <<" ";
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
	
	run();

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] =='G') {
				map[i][j] = 'R';
			}
		}
	}
	run();
}
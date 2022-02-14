// https://www.acmicpc.net/problem/1012
// 유기농 배추
#include<iostream>
#include<cstring>
using namespace std;
bool map[51][51];

int T, M, N, K, X, Y, cnt = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y) {
	map[x][y] = false;
	for (int i = 0; i < 4; i++) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];

		if (tmpx < 0 || tmpy < 0 || tmpx >= M || tmpy >= N) continue;

		if (!map[tmpx][tmpy]) continue;

		dfs(tmpx, tmpy);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;

	for (int t = 0; t < T; t++) {
		// M, N  : 가로, 세로, K 배추
		cin >> M >> N >> K;

		//X, Y : 배추 좌표
		for (int k = 0; k < K; k++) {
			cin >> X >> Y;
			map[X][Y] = true;
		}
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (map[x][y]) {
					cnt++;
					dfs(x, y);
				}
			}
		}
		cout << cnt << "\n";

		memset(map, false, sizeof(map));
		cnt = 0;
	}
}
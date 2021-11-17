// https://www.acmicpc.net/problem/14499
// ¡÷ªÁ¿ß ±º∏Æ±‚
#include<iostream>
#include<cstring>
using namespace std;
int N, M, x, y, K;
int map[21][21];
int dice[8];
int tmpdice[8];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
void roll(int cmd) {

	memcpy(tmpdice, dice, sizeof(dice));
	// µø
	if (cmd == 1) {
		dice[1] = tmpdice[3];
		dice[3] = tmpdice[6];
		dice[4] = tmpdice[1];
		dice[6] = tmpdice[4];
	}
	// º≠
	else if (cmd == 2) {
		dice[1] = tmpdice[4];
		dice[3] = tmpdice[1];
		dice[4] = tmpdice[6];
		dice[6] = tmpdice[3];
	}
	// ∫œ
	else if (cmd == 3) {
		dice[1] = tmpdice[2];
		dice[2] = tmpdice[6];
		dice[5] = tmpdice[1];
		dice[6] = tmpdice[5];
	}
	// ≥≤
	else if (cmd == 4) {
		dice[1] = tmpdice[5];
		dice[2] = tmpdice[1];
		dice[5] = tmpdice[6];
		dice[6] = tmpdice[2];
	}
	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	dice[6] = map[x][y];

	int cmd;

	for (int i = 0; i < K; i++) {
		cin >> cmd;
		int ny = y + dy[cmd];
		int nx = x + dx[cmd];
		if (nx < 0 || nx >= N || ny <0 || ny >= M) continue;
		x = nx;
		y = ny;
		roll(cmd);
		cout << dice[1] << "\n";
	}
}
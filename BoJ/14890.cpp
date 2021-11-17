// https://www.acmicpc.net/problem/14890
// °æ»ç·Î
// reference by wizely 
#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int map[101][101] = { 0, };
int res = 0;

void checkX(int x) {
	int cnt = 1;
	for (int j = 0; j < N - 1; j++) {
		int v = map[x][j + 1] - map[x][j];
		if (v == 0) cnt++;
		else if (v == 1 && cnt >= L) cnt = 1;
		else if (v == -1 && cnt >= 0) cnt = -L + 1;
		else return;
	}
	if (cnt >= 0) res++;
}

void checkY(int y) {
	int cnt = 1;
	for (int j = 0; j < N - 1; j++) {
		int v = map[j + 1][y] - map[j][y];
		if (v == 0) cnt++;
		else if (v == 1 && cnt >= L) cnt = 1;
		else if (v == -1 && cnt >= 0) cnt = -L + 1;
		else return;
	}
	if (cnt >= 0)res++;
}


void simulation() {
	for (int i = 0; i < N; i++) {
		checkX(i);
		checkY(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	simulation();
	cout << res << "\n";

	return 0;

}
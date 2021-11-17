#include<iostream>
#include<algorithm>

using namespace std;

char wbboard[9][9] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
char bwboard[9][9] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
char jboard[51][51] = { 0, };

int bwcnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (jboard[x + i][y + j] != bwboard[i][j]) cnt++;
		}
	}
	return cnt;
}
int wbcnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (jboard[x + i][y + j] != wbboard[i][j]) cnt++;
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> jboard[i][j];
		}
	}
	int Min = 99999999, tmp;
	for (int i = 0; i + 8 <= N; i++) {
		for (int j = 0; j + 8 <= M; j++) {
			tmp = min(bwcnt(i, j), wbcnt(i, j));
			Min = min(tmp, Min);
		}
	}
	cout << Min;
}
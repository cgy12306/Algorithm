// https://www.acmicpc.net/problem/10159
// Àú¿ï
#include<iostream>
using namespace std;
int N, M;
bool map[102][102];
void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][k] && map[k][j]) {
					map[i][j] = true;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		map[from][to] = true;
	}

	floyd();
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			if (!map[i][j] && !map[j][i]) cnt++;
		}
		cout << cnt <<"\n";
		cnt = 0;
	}
}
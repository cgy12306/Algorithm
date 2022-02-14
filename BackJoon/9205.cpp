// https://www.acmicpc.net/problem/9205
// 맥주 마시면서 걸어가기
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int T, N, x, y;
bool arr[102][102];

void floyd_warshall() {
	for (int k = 0; k < N + 2; k++) {
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				if (arr[i][k] && arr[k][j]) {
					arr[i][j] = true;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		
		cin >> N;
		vector<pair<int, int>> V;
		for (int n = 0; n < N + 2; n++) {
			cin >> x >> y;
			V.push_back(make_pair(x, y));
		}

		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				int distance = abs(V[i].first - V[j].first) + abs(V[i].second - V[j].second);
				if (distance > 1000) continue;
				arr[i][j] = true;
			}
		}
		floyd_warshall();
		if (arr[0][N + 1]) cout << "happy\n";
		else cout << "sad\n";
		memset(arr, false, sizeof(arr));
	}

}
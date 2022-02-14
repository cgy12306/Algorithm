// https://www.acmicpc.net/problem/11660
// 구간 합 구하기 5
#include<iostream>

using namespace std;
int arr[1026][1026], dp[1026][1026];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
			dp[i][j] = sum;
		}
	}

	for (int m = 0; m < M; m++) {
		int x1, x2, y1, y2, ans = 0;

		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x <= x2; x++) {
			if (y1 == 1) ans += dp[x][y2] - dp[x - 1][N];
			else ans += dp[x][y2] - dp[x][y1 - 1];
		}
		cout << ans << "\n";
	}
}
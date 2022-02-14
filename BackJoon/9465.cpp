// https://www.acmicpc.net/problem/9465
// ½ºÆ¼Ä¿

#include<iostream>
#include<algorithm>
using namespace std;
int arr[2][100001], dp[2][100001];

void print(int arr[2][100001], int n) {
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, x, dp1 = 0, dp2 = 0;
	cin >> m;

	for (int a = 0; a < m; a++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> x;
				arr[i][j] = x;
			}
		}
		if (n == 1) {
			if (arr[0][1] >= arr[1][1]) cout << arr[1][1] << "\n";
			else cout << arr[1][1] << "\n";
		}
		else if (n == 2) {
			if (arr[0][1] + arr[1][2] >= arr[1][1] + arr[0][2]) cout << arr[0][1] + arr[1][2] << "\n";
			else cout << arr[1][1] + arr[0][2] << "\n";
		}
		else {
			dp[0][1] = arr[0][1];
			dp[1][1] = arr[1][1];

			dp[0][2] = arr[0][2] + arr[1][1];
			dp[1][2] = arr[1][2] + arr[0][1];

			for (int i = 3; i <= n; i++) {
				dp[0][i] = max(dp[1][i - 1] + arr[0][i], dp[1][i - 2] + arr[0][i]);
				dp[1][i] = max(dp[0][i - 1] + arr[1][i], dp[0][i - 2] + arr[1][i]);
			}
			cout << max(dp[0][n], dp[1][n]) << "\n";
		}
		//print(dp, n);
	}
}
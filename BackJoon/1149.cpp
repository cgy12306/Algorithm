// https://www.acmicpc.net/problem/1149
// RGB°Å¸®
#include<iostream>
#include<algorithm>

using namespace std;
int arr[1002][1002], dp[1002][1002];
int N;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	dp[1][3] = arr[1][3];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1) {
				dp[i][j] = min(dp[i - 1][j + 1] + arr[i][j], dp[i - 1][j + 2] + arr[i][j]);
			}
			else if (j == 2) {
				dp[i][j] = min(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j + 1] + arr[i][j]);
			}
			else if (j == 3) {
				dp[i][j] = min(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j - 2] + arr[i][j]);
			}
		}
	}
	int Min = 999999999;
	
	for (int i = 1; i <= 3; i++) {
		Min = min(dp[N][i], Min);
	}

	cout << Min;
}
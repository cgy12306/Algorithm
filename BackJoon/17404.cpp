// https://www.acmicpc.net/problem/17404
// RGB°Å¸® 2
#include<iostream>
#include<algorithm>

using namespace std;
int N, arr[1002][1002], dp[1002][1002];
const int INF = 999999999;
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	
	int Min = INF;
	for (int rgb = 1; rgb <= 3; rgb++) {
		for (int i = 1; i <= 3; i++) {
			if (i == rgb) dp[1][i] = arr[1][i];
			else dp[1][i] = INF;
		}

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
		/*
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 3; j++) {
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		*/
		for (int i = 1; i <= 3; i++) {
			if (i == rgb) continue;
			else Min = min(dp[N][i], Min);
		}
	}
	cout << Min;
}
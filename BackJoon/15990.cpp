// https://www.acmicpc.net/problem/15990
// 1, 2, 3 ¥ı«œ±‚ 5
#include<iostream>
#include<algorithm>
using namespace std;

long long dp[100002][4];
const int MOD = 1000000009;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		
		dp[1][1] = 1;
		dp[2][2] = 1;
		dp[3][1] = 1;
		dp[3][2] = 1;
		dp[3][3] = 1;

		for (int i = 4; i <= N; i++) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
		}

		cout << (dp[N][1] + dp[N][2] + dp[N][3]) % MOD <<"\n";
	}
}

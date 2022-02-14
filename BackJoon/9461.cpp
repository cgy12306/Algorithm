// https://www.acmicpc.net/problem/9461
// 파도반 수열

#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long dp[101];

	int n, a;
	cin >> a;
	for (int j = 0; j < a; j++) {
		cin >> n;

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		for (int i = 6; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[n] << "\n";
	}
	

}

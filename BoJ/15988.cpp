#include<iostream>
using namespace std;
long long dp[1000002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] % 1000000009;
			dp[i] += dp[i - 2] % 1000000009;
			dp[i] += dp[i - 3] % 1000000009;
		}
		cout << dp[n] % 1000000009<<"\n";
	}
}
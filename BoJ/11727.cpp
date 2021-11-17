// https://www.acmicpc.net/problem/11727
// 2xn ≈∏¿œ∏µ 2

#include<iostream>
using namespace std;
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % 10007;
	}
	cout << dp[n];
}
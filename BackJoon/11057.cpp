// https://www.acmicpc.net/problem/11057
// 오르막 수

#include<iostream>
using namespace std;
long long dp[12];

int main() {
	
	int n;

	cin >> n;

	for (int i = 1; i <= 10; i++) {
		dp[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= 10; j++) {
			dp[j] += dp[j - 1];
			dp[j] %= 10007;
		}
	}
	cout << dp[10];
}
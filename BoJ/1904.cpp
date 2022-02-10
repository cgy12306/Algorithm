// https://www.acmicpc.net/problem/1904
// 01≈∏¿œ
#include<iostream>
using namespace std;
int dp[1000002];
const int MOD = 15746;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[N];
	
}
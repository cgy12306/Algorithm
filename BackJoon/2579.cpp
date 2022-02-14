// https://www.acmicpc.net/problem/2579
// 계단 오르기
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, stair[301], dp[301];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}
	
	dp[0] = stair[0];
	dp[1] = max(stair[0] + stair[1], stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
		// max(마지막계단 + 전전꺼의 합, 마지막계단 + 전꺼 + 전전전꺼의 합) 
	}
	cout << dp[n - 1];
	
}
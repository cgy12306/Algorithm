// https://www.acmicpc.net/problem/2156
// 포도주 시식

#include<iostream>
#include<algorithm>

using namespace std;
int arr[10001], dp[10001];
int N;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N;

	for (int i = 3; i < N + 3; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 3; i < N + 3; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = max(dp[i], dp[i - 1]);
		sum = max(sum, dp[i]);
	}
	cout << sum;

}
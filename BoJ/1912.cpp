// https://www.acmicpc.net/problem/1912
// ¿¬¼ÓÇÕ

#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, dp[100001] = { 0, }, arr[100001] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int sum = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		sum = max(sum, dp[i]);
	}
	cout << sum;
}
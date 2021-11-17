// https://www.acmicpc.net/problem/11055
// 가장 큰 증가하는 부분 수열

#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001] = { 0, }, dp[1001] = { 0, };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
	}

	cout << *max_element(dp, dp+n);
}
// https://www.acmicpc.net/problem/11722
// 가장 긴 감소하는 부분 수열

#include<iostream>
#include<algorithm>

using namespace std;
int arr[1001], dp[1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	fill(dp, dp + 1000, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int res;

	res = *max_element(dp, dp + n);
	
	cout << res;
}
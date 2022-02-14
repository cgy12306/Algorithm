// https://www.acmicpc.net/problem/1932
// Á¤¼ö »ï°¢Çü
#include<iostream>
#include<algorithm>
using namespace std;
int arr[501][501], dp[502][502];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, res = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	
	for (int i = 2; i <= N; i++) {
		dp[i][1] = arr[i][1] + dp[i - 1][1];
		for (int j = 2; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i - 1][j - 1] + arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		res = max(dp[N][i], res);
	}
	
	cout << res;
}
// https://www.acmicpc.net/problem/11659
// 구간 합 구하기 4
#include<iostream>
using namespace std;
int arr[100002], dp[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += arr[i];
		dp[i] = sum;
	}

	for (int i = 0; i < M; i++) {
		int from, to, ans;
		cin >> from >> to;

		ans = dp[to] - dp[from - 1];
		cout << ans <<"\n";
	}
}
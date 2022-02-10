// https://www.acmicpc.net/problem/1965
// 상자넣기
#include<iostream>
#include<algorithm>
using namespace std;
int box[1002], dp[1002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> box[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (box[i] > box[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
	}
	int Max = 0;
	for (int i = 1; i <= N; i++) Max = max(dp[i], Max);
	cout << Max;
}
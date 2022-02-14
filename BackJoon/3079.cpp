// https://www.acmicpc.net/problem/3079
// 입국심사
#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
long long T[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	long long m = 0;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		m = max(T[i], m);
	}
	
	long long right = m * M;
	long long left = 0;
	long long answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += mid / T[i];
		}

		if (sum < M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			answer = mid;
		}
	}
	cout << answer;
}
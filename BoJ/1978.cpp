// https://www.acmicpc.net/problem/1978
// 소수 찾기

#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	bool arr[1001] = { 0, };
	cin >> N;

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= 1001; i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j <= 1001; j += i) arr[j] = 1;
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (!arr[a]) cnt++;
	}
	cout << cnt;
}
// https://www.acmicpc.net/problem/1929
// 소수 구하기

#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n;
	bool arr[1000001]{ 0, };

	cin >> m >> n;

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			arr[j] = 1;
		}
	}

	for (int i = m; i <= n; i++) {
		if (!arr[i]) cout << i << "\n";
	}

}
// https://www.acmicpc.net/problem/4948
// 베르트랑 공준
#include<iostream>

using namespace std;
bool is_prime(int num) {
	if (num == 1) return false;

	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) return false;
	}
	return true;
}
int main() {
	int N;
	
	while (1) {
		cin >> N;
		int cnt = 0;

		if (N == 0) break;

		for (int i = N + 1; i <= N * 2; i++) {
			if (is_prime(i)) cnt++;
		}
		cout << cnt << "\n";
	}
}

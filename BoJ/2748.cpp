// https://www.acmicpc.net/problem/2748
// [2748] 피보나치 수 2
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, F[10001] = { 0,1, }, sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		F[i + 2] = F[i] + F[i + 1];
	}
	cout << F[N];

}
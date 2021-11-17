#include<iostream>
using namespace std;

int hap(int N) {
	int sum = N;
	while (N) {
		sum += N % 10;
		N /= 10;
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, sum = 0;
	cin >> N;

	for (int i = 1; i < N; i++) {
		sum = hap(i);
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << '0';
}
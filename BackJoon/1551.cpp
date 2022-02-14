// https://www.acmicpc.net/submit/1551
// [1551] 수열의 변화

#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, a, A[21] = { 0, };
	char comma;
	cin >> N >> K;
	
	cin >> A[0];
	for (int j = 1; j < N; j++) {
		cin >> comma >> a;
		A[j] = a;
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			A[j] = A[j + 1] - A[j];
		}
	}
	
	cout << A[0];
	for (int i = 1; i < N - K; i++) {
		cout << "," << A[i];
	}
	cout << "\n";
	
}
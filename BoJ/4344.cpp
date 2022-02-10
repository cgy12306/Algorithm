#include<iostream>
#include<cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int C, N, arr[1001];
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> N;
		float sum = 0;

		memset(arr, 0, sizeof(arr));

		for (int n = 0; n < N; n++) {
			cin >> arr[n];
			sum += arr[n];
		}

		float avg = sum / N;
		
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			if (arr[i] > avg) {
				cnt++;
			}
		}
		
		float res = (float)cnt / N * 100;
		cout << fixed;
		cout.precision(3);
		cout << res<<"%\n";
		

	}
}
// https://www.acmicpc.net/problem/13458
// 시험 감독
#include<iostream>
using namespace std;
int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, B, C;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> B >> C;

	long long cnt = 0;

	for (int i = 0; i < N; i++) {
		arr[i] -= B;
		cnt++;
		if (arr[i] > 0) {
			cnt += arr[i] / C;
			if (arr[i] % C > 0) cnt++;
		}
	}
	cout << cnt;

}
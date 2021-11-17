// https://www.acmicpc.net/problem/1654
// 랜선 자르기

#include<iostream>
#include<algorithm>
using namespace std;

long long K, N, lan[10001], low, high, mid, res;

bool check(long long length) {
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += lan[i] / length;
	}
	if (cnt >= N) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> lan[i];
	}

	low = 1;
	high = *max_element(lan, lan+K);

	while (low <= high) {
		mid = (low + high) / 2;
		
		if (check(mid)) {
			if (res < mid) res = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << res << "\n";

}
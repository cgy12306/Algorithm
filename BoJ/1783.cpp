// https://www.acmicpc.net/problem/1783
// 병든 나이트
#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, res;

	cin >> N;
	cin >> M;

	if (N == 1) {
		res = 1;
	}
	else if (N == 2) {
		res = min(4, (M + 1) / 2 );
	}
	else if (M < 7) {
		res = min(4, M);
	}
	else {
		res = M - 7 + 5;
	}
	cout << res;

	return 0;
}
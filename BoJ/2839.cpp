// https://www.acmicpc.net/problem/2839
// º≥≈¡ πË¥ﬁ
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, cnt = 0;
	cin >> N;
	
	if (N % 5 == 0) {
		cout << N / 5;
	}
	else {
		while (1) {
			if (N % 5 == 0) {
				cnt += N / 5;
				cout << cnt;
				break;
			}

			N -= 3;
			cnt++;

			if (N < 0) {
				cout << "-1";
				break;
			}
		}
	}
	
}
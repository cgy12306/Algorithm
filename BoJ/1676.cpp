// https://www.acmicpc.net/problem/1676
// ���丮�� 0�� ����

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, twocnt = 0, fivecnt = 0;
	cin >> N;
	for (int i = 2; i <= N; i*=2) {
		twocnt += N / i;
	}

	for (int i = 5; i <= N; i *= 5) {
		fivecnt += N / i;
	}
	cout << min(twocnt, fivecnt);
}
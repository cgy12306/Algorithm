// https://www.acmicpc.net/problem/1676
// 팩토리얼 0의 개수

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
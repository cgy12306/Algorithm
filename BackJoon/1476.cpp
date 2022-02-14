// https://www.acmicpc.net/problem/1476
// [1476] - 날짜계산

#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int E, S, M, year = 1;
	cin >> E >> S >> M;

	while (!(E == 1 && S == 1 && M == 1)) {
		E--; S--; M--;
		if (E == 0) E = 15;
		if (S == 0) S = 28;
		if (M == 0) M = 19;
		year++;
	}
	cout << year;

	return 0;
}
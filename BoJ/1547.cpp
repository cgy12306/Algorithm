// https://www.acmicpc.net/problem/1547
// [1547] °ø
#include<iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, X, Y, res = 1;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		if (res == X) {
			res = Y;
		}
		else if (res == Y) {
			res = X;
		}
		else {
			res = res;
		}
	}
	cout << res;

}
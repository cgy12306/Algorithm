#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int DP[1000001] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int X, a, b, c;

	cin >> X;

	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;
	for (int i = 4; i <= X; i++) {
		a = X;
		b = X;
		if (i % 2 == 0) a = DP[i / 2] + 1;
		if (i % 3 == 0) b = DP[i / 3] + 1;
		c = DP[i - 1] + 1;
		DP[i] = min({ a,b,c });
	}
	cout << DP[X];
	
}
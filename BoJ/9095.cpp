// https://www.acmicpc.net/problem/9095
// 1,2,3 ¥ı«œ±‚
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, DP[12] ,T;
	cin >> n;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for (int i = 0; i < n; i++) {
		cin >> T;
		for (int j = 4; j <= T; j++) {
			DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
		}
		cout << DP[T] <<"\n";
	}
	
	
}
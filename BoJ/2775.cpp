#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, k, n;
	int apt[15][15];
	apt[0][1] = 1;
	for (int i = 2; i < 15; i++) {
		apt[0][i] = apt[0][i - 1] + i;
	}

	for (int i = 1; i < 14; i++) {
		apt[i][1] = apt[i - 1][1];
		for (int j = 2; j < 15; j++) {
			apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << apt[k - 1][n] <<"\n";
	}
}



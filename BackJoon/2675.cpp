#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, R;
	string S;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		for (int k = 0; k < S.size(); k++) {
			for (int j = 0; j < R; j++) {
				cout << S[k];
			}
		}
		cout << "\n";
	}

}
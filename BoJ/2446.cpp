#include<iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = (n * 2) - (i * 2) - 1; j > 0; j--) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			cout << " ";
		}
		for (int j = 0; j < (i * 2) + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

}
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[8] = { 0, };

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	
	bool asc = true, desc = true;

	for (int i = 0; i < 8; i++) {
		if (arr[i] != i + 1) {
			asc = false;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (arr[i] != 8 - i) {
			desc = false;
		}
	}

	if (asc) cout << "ascending";
	else if (desc) cout << "descending";
	else cout << "mixed";
}
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num[10] = { 0, };
	
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	int max = 0, tmp_idx=0;
	for (int i = 0; i < 9; i++) {
		if (max < num[i]) {
			max = num[i];
			tmp_idx = i;
		}
	}
	cout << max << "\n" << tmp_idx + 1;
}
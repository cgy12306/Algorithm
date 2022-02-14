// https://www.acmicpc.net/problem/2947
// 나무조각
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int wood[6];

	for (int i = 0; i < 5; i++) {
		cin >> wood[i];
	}
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 4; i++) {
			if (wood[i] > wood[i + 1]) {
				swap(wood[i], wood[i + 1]);
				for (int j = 0; j < 5; j++) {
					cout << wood[j] << " ";
				}
				cout << "\n";
			}
		}
	}
}
